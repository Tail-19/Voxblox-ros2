#include <cstring>

#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/camera_info.h>
#include <sensor_msgs/msg/image.h>
#include <sensor_msgs/msg/point_cloud2.h>
#include <sensor_msgs/image_encodings.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <builtin_interfaces/msg/time.hpp>

#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.hpp>
#include <image_transport/subscriber.h>
#include <image_transport/subscriber_filter.h>

#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/synchronizer.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Transform.h>
#include <tf2/LinearMath/Quaternion.h>

#include <pcl/PCLPointCloud2.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>

#include <Eigen/Core>

#include "vpp_interfaces/msg/result.hpp"

#include "depth_segmentation_ros2/ros_common.h" //TODO: alter the opencv to colcon
#include "depth_segmentation_ros2/depth_segmentation.h"
#include "depth_segmentation_ros2/common.h"

typedef message_filters::sync_policies::ApproximateTime<
  sensor_msgs::msg::Image,
  sensor_msgs::msg::Image,
  vpp_interfaces::msg::Result> ImageSegmentationSyncPolicy;

typedef message_filters::sync_policies::ApproximateTime<
    sensor_msgs::msg::Image,
    sensor_msgs::msg::Image> ImageSyncPolicy;

typedef message_filters::sync_policies::ApproximateTime<
    sensor_msgs::msg::CameraInfo,
    sensor_msgs::msg::CameraInfo> CameraInfoSyncPolicy;

struct PointSurfelLabel {
  PCL_ADD_POINT4D;
  PCL_ADD_NORMAL4D;
  PCL_ADD_RGB;
  uint8_t instance_label;
  uint8_t semantic_label;

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;

POINT_CLOUD_REGISTER_POINT_STRUCT(
    PointSurfelLabel,
    (float, x, x)(float, y, y)(float, z, z)(float, normal_x, normal_x)(
        float, normal_y, normal_y)(float, normal_z, normal_z)(float, rgb, rgb)(
        uint8_t, instance_label, instance_label)(uint8_t, semantic_label,
                                                 semantic_label))

class DepthSegmentationNode : public rclcpp::Node {
 public:DepthSegmentationNode()
      : Node("depth_segmentation_node"), 
        node(rclcpp::Node::make_shared(this->get_name())),
        camera_info_ready_(false),
        depth_camera_(),
        rgb_camera_(),
        params_(),
        camera_tracker_(depth_camera_, rgb_camera_),
        depth_segmenter_(depth_camera_, params_) {
    // Set up parameters.
    declareParameters();

    rgb_image_topic_ = this->get_parameter("rgb_image_sub_topic").as_string();
    rgb_camera_info_topic_ = this->get_parameter("rgb_camera_info_sub_topic").as_string();
    depth_image_topic_ = this->get_parameter("depth_image_sub_topic").as_string();
    depth_camera_info_topic_ = this->get_parameter("depth_camera_info_sub_topic").as_string();
    semantic_instance_segmentation_topic_ = this->get_parameter("semantic_instance_segmentation_sub_topic").as_string();
    world_frame_ = this->get_parameter("world_frame").as_string();
    camera_frame_ = this->get_parameter("camera_frame").as_string();

    depth_image_sub_ = std::make_shared<image_transport::SubscriberFilter>(this, depth_image_topic_, std::string("raw")); //or "compressed"
    rgb_image_sub_ = std::make_shared<image_transport::SubscriberFilter>(this, rgb_image_topic_, std::string("raw")); //or "compressed"
    depth_info_sub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::CameraInfo>>(this, depth_camera_info_topic_);
    rgb_info_sub_ = std::make_shared<message_filters::Subscriber<sensor_msgs::msg::CameraInfo>>(this, rgb_camera_info_topic_);
 
    constexpr int kQueueSize = 30;

    if (params_.semantic_instance_segmentation.enable) {
      // #ifdef MASKRCNNROS_AVAILABLE
      instance_segmentation_sub_ = std::make_shared<message_filters::Subscriber<vpp_interfaces::msg::Result>>(
          this, semantic_instance_segmentation_topic_);

      image_segmentation_sync_policy_ = std::make_shared<message_filters::Synchronizer<ImageSegmentationSyncPolicy>>(
          ImageSegmentationSyncPolicy(kQueueSize), 
          *depth_image_sub_, 
          *rgb_image_sub_, 
          *instance_segmentation_sub_);

      image_segmentation_sync_policy_->registerCallback(
          std::bind(&DepthSegmentationNode::imageSegmentationCallback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
      // #endif
    } else {
      image_sync_policy_ = std::make_shared<message_filters::Synchronizer<ImageSyncPolicy>>(
          ImageSyncPolicy(kQueueSize), 
          *depth_image_sub_, 
          *rgb_image_sub_);

      image_sync_policy_->registerCallback(
          std::bind(&DepthSegmentationNode::imageCallback, this, std::placeholders::_1, std::placeholders::_2));
    }

    point_cloud2_segment_pub_ =
        this->create_publisher<sensor_msgs::msg::PointCloud2>("object_segment", 1000);
    point_cloud2_scene_pub_ =
        this->create_publisher<sensor_msgs::msg::PointCloud2>("segmented_scene", 1);

    camera_info_sync_policy_ = std::make_shared<message_filters::Synchronizer<CameraInfoSyncPolicy>>(
      CameraInfoSyncPolicy(kQueueSize), 
      *depth_info_sub_, 
      *rgb_info_sub_);
    camera_info_sync_policy_->registerCallback(
        std::bind(&DepthSegmentationNode::cameraInfoCallback, this, std::placeholders::_1, std::placeholders::_2));
  }
  
private:
  std::shared_ptr<rclcpp::Node> node;
  std::shared_ptr<image_transport::ImageTransport> image_transport_;
  // ros::NodeHandle node_handle_;
  tf2_ros::TransformBroadcaster transform_broadcaster_ = tf2_ros::TransformBroadcaster(this);

  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image>
      ImageSyncPolicy;

  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::Image, sensor_msgs::msg::Image, vpp_interfaces::msg::Result>
    ImageSegmentationSyncPolicy;

  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::msg::CameraInfo, sensor_msgs::msg::CameraInfo>
      CameraInfoSyncPolicy;

  bool camera_info_ready_;
  depth_segmentation::DepthCamera depth_camera_;
  depth_segmentation::RgbCamera rgb_camera_;
  depth_segmentation::Params params_;

public:
  depth_segmentation::CameraTracker camera_tracker_;
  depth_segmentation::DepthSegmenter depth_segmenter_;

private:
  std::string rgb_image_topic_;
  std::string rgb_camera_info_topic_;
  std::string depth_image_topic_;
  std::string depth_camera_info_topic_;
  std::string semantic_instance_segmentation_topic_ ;
  std::string world_frame_ ;
  std::string camera_frame_;

  std::shared_ptr<image_transport::SubscriberFilter> depth_image_sub_;
  std::shared_ptr<image_transport::SubscriberFilter> rgb_image_sub_;
  std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::CameraInfo>> depth_info_sub_;
  std::shared_ptr<message_filters::Subscriber<sensor_msgs::msg::CameraInfo>> rgb_info_sub_;

  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud2_segment_pub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr point_cloud2_scene_pub_;

  std::shared_ptr<message_filters::Synchronizer<ImageSyncPolicy>> image_sync_policy_;
  std::shared_ptr<message_filters::Synchronizer<CameraInfoSyncPolicy>> camera_info_sync_policy_;

  std::shared_ptr<message_filters::Synchronizer<ImageSegmentationSyncPolicy>> image_segmentation_sync_policy_;
  std::shared_ptr<message_filters::Subscriber<vpp_interfaces::msg::Result>> instance_segmentation_sub_;

  void publish_tf(const cv::Mat cv_transform, const builtin_interfaces::msg::Time& timestamp) {
    // Rotate such that the world frame initially aligns with the camera_link
    // frame.
    static const cv::Mat kWorldAlign =
        (cv::Mat_<double>(4, 4) << 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0,
         1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    cv::Mat cv_transform_world_aligned = cv_transform * kWorldAlign;

    tf2::Vector3 translation_tf(
        cv_transform_world_aligned.at<double>(0, 3),
        cv_transform_world_aligned.at<double>(1, 3),
        cv_transform_world_aligned.at<double>(2, 3)
    );

    tf2::Matrix3x3 rotation_tf;
    for (size_t i = 0u; i < 3u; ++i) {
      for (size_t j = 0u; j < 3u; ++j) {
        rotation_tf[j][i] = cv_transform_world_aligned.at<double>(j, i);
      }
    }
    tf2::Transform transform;
    transform.setOrigin(translation_tf);
    transform.setBasis(rotation_tf);

    // Convert tf2 Transform to geometry_msgs::msg::TransformStamped
    geometry_msgs::msg::TransformStamped transform_stamped;
    transform_stamped.header.stamp = timestamp;
    transform_stamped.header.frame_id = world_frame_;     // Ensure this is defined
    transform_stamped.child_frame_id = camera_frame_;    // Ensure this is defined

    // Set translation
    transform_stamped.transform.translation.x = transform.getOrigin().x();
    transform_stamped.transform.translation.y = transform.getOrigin().y();
    transform_stamped.transform.translation.z = transform.getOrigin().z();

    // Set rotation (convert tf2 Quaternion to geometry_msgs Quaternion)
    tf2::Quaternion q = transform.getRotation();
    transform_stamped.transform.rotation.x = q.x();
    transform_stamped.transform.rotation.y = q.y();
    transform_stamped.transform.rotation.z = q.z();
    transform_stamped.transform.rotation.w = q.w();

    transform_broadcaster_.sendTransform(transform_stamped);
  }

  void fillPoint(const cv::Vec3f& point, const cv::Vec3f& normals,
                 const cv::Vec3f& colors, pcl::PointSurfel* point_pcl) {
    point_pcl->x = point[0];
    point_pcl->y = point[1];
    point_pcl->z = point[2];
    point_pcl->normal_x = normals[0];
    point_pcl->normal_y = normals[1];
    point_pcl->normal_z = normals[2];
    point_pcl->r = colors[0];
    point_pcl->g = colors[1];
    point_pcl->b = colors[2];
  }

  void fillPoint(const cv::Vec3f& point, const cv::Vec3f& normals,
                 const cv::Vec3f& colors, const size_t& semantic_label,
                 const size_t& instance_label, PointSurfelLabel* point_pcl) {
    point_pcl->x = point[0];
    point_pcl->y = point[1];
    point_pcl->z = point[2];
    point_pcl->normal_x = normals[0];
    point_pcl->normal_y = normals[1];
    point_pcl->normal_z = normals[2];
    point_pcl->r = colors[0];
    point_pcl->g = colors[1];
    point_pcl->b = colors[2];

    point_pcl->semantic_label = semantic_label;
    point_pcl->instance_label = instance_label;
  }

  void publish_segments(
      const std::vector<depth_segmentation::Segment>& segments,
      const std_msgs::msg::Header& header) {
    CHECK_GT(segments.size(), 0u);
    // Just for rviz also publish the whole scene, as otherwise only ~10
    // segments are shown:
    // https://github.com/ros-visualization/rviz/issues/689
    sensor_msgs::msg::PointCloud2 pcl2_msg;

    if (params_.semantic_instance_segmentation.enable) {
      pcl::PointCloud<PointSurfelLabel>::Ptr scene_pcl(
          new pcl::PointCloud<PointSurfelLabel>);
      for (depth_segmentation::Segment segment : segments) {
        CHECK_GT(segment.points.size(), 0u);
        pcl::PointCloud<PointSurfelLabel>::Ptr segment_pcl(
            new pcl::PointCloud<PointSurfelLabel>);
        for (std::size_t i = 0u; i < segment.points.size(); ++i) {
          PointSurfelLabel point_pcl;
          uint8_t semantic_label = 0u;
          uint8_t instance_label = 0u;
          if (segment.instance_label.size() > 0u) {
            instance_label = *(segment.instance_label.begin());
            semantic_label = *(segment.semantic_label.begin());
          }
          fillPoint(segment.points[i], segment.normals[i],
                    segment.original_colors[i], semantic_label, instance_label,
                    &point_pcl);

          segment_pcl->push_back(point_pcl);
          scene_pcl->push_back(point_pcl);
        }
        sensor_msgs::msg::PointCloud2 pcl2_msg;
        pcl::toROSMsg(*segment_pcl, pcl2_msg);
        pcl2_msg.header.stamp = header.stamp;
        pcl2_msg.header.frame_id = header.frame_id;
        point_cloud2_segment_pub_->publish(pcl2_msg);
      }
      if (params_.visualize_segmented_scene) {
        pcl::toROSMsg(*scene_pcl, pcl2_msg);
      }
    } else {
      pcl::PointCloud<pcl::PointSurfel>::Ptr scene_pcl(
          new pcl::PointCloud<pcl::PointSurfel>);
      for (depth_segmentation::Segment segment : segments) {
        CHECK_GT(segment.points.size(), 0u);
        pcl::PointCloud<pcl::PointSurfel>::Ptr segment_pcl(
            new pcl::PointCloud<pcl::PointSurfel>);
        for (std::size_t i = 0u; i < segment.points.size(); ++i) {
          pcl::PointSurfel point_pcl;

          fillPoint(segment.points[i], segment.normals[i],
                    segment.original_colors[i], &point_pcl);

          segment_pcl->push_back(point_pcl);
          scene_pcl->push_back(point_pcl);
        }
        sensor_msgs::msg::PointCloud2 pcl2_msg;
        pcl::toROSMsg(*segment_pcl, pcl2_msg);
        pcl2_msg.header.stamp = header.stamp;
        pcl2_msg.header.frame_id = header.frame_id;
        point_cloud2_segment_pub_->publish(pcl2_msg);
      }
      if (params_.visualize_segmented_scene) {
        pcl::toROSMsg(*scene_pcl, pcl2_msg);
      }
    }

    if (params_.visualize_segmented_scene) {
      pcl2_msg.header.stamp = header.stamp;
      pcl2_msg.header.frame_id = header.frame_id;
      point_cloud2_scene_pub_->publish(pcl2_msg);
    }
  }

// #ifdef MASKRCNNROS_AVAILABLE
  void semanticInstanceSegmentationFromRosMsg(const vpp_interfaces::msg::Result::ConstPtr& segmentation_msg,
      depth_segmentation::SemanticInstanceSegmentation* semantic_instance_segmentation) {
    semantic_instance_segmentation->masks.reserve(
        segmentation_msg->masks.size());
    semantic_instance_segmentation->labels.reserve(
        segmentation_msg->masks.size());
    for (size_t i = 0u; i < segmentation_msg->masks.size(); ++i) {
      cv_bridge::CvImagePtr cv_mask_image;
      cv_mask_image = cv_bridge::toCvCopy(segmentation_msg->masks[i],
                                          sensor_msgs::image_encodings::MONO8);
      semantic_instance_segmentation->masks.push_back(
          cv_mask_image->image.clone());
      semantic_instance_segmentation->labels.push_back(
          segmentation_msg->class_ids[i]);
    }
  }
// #endif

  void preprocess(const sensor_msgs::msg::Image::ConstPtr& depth_msg,
                  const sensor_msgs::msg::Image::ConstPtr& rgb_msg,
                  cv::Mat* rescaled_depth, cv::Mat* dilated_rescaled_depth,
                  cv_bridge::CvImagePtr cv_rgb_image,
                  cv_bridge::CvImagePtr cv_depth_image, cv::Mat* bw_image,
                  cv::Mat* mask) {
    CHECK_NOTNULL(rescaled_depth);
    CHECK_NOTNULL(dilated_rescaled_depth);
    CHECK(cv_rgb_image);
    CHECK(cv_depth_image);
    CHECK_NOTNULL(bw_image);
    CHECK_NOTNULL(mask);

    if (depth_msg->encoding == sensor_msgs::image_encodings::TYPE_16UC1) {
      cv_depth_image = cv_bridge::toCvCopy(
          depth_msg, sensor_msgs::image_encodings::TYPE_16UC1);
      *rescaled_depth = cv::Mat::zeros(cv_depth_image->image.size(), CV_32FC1);
      cv::rgbd::rescaleDepth(cv_depth_image->image, CV_32FC1, *rescaled_depth);
    } else if (depth_msg->encoding ==
               sensor_msgs::image_encodings::TYPE_32FC1) {
      cv_depth_image = cv_bridge::toCvCopy(
          depth_msg, sensor_msgs::image_encodings::TYPE_32FC1);
      *rescaled_depth = cv_depth_image->image;
    } else {
      LOG(FATAL) << "Unknown depth image encoding.";
    }

    constexpr double kZeroValue = 0.0;
    cv::Mat nan_mask = *rescaled_depth != *rescaled_depth;
    rescaled_depth->setTo(kZeroValue, nan_mask);

    if (params_.dilate_depth_image) {
      cv::Mat element = cv::getStructuringElement(
          cv::MORPH_RECT, cv::Size(2u * params_.dilation_size + 1u,
                                   2u * params_.dilation_size + 1u));
      cv::morphologyEx(*rescaled_depth, *dilated_rescaled_depth,
                       cv::MORPH_DILATE, element);
    } else {
      *dilated_rescaled_depth = *rescaled_depth;
    }

    *bw_image = cv::Mat::zeros(cv_rgb_image->image.size(), CV_8UC1);

    cvtColor(cv_rgb_image->image, *bw_image, cv::COLOR_RGB2GRAY);

    *mask = cv::Mat::zeros(bw_image->size(), CV_8UC1);
    mask->setTo(cv::Scalar(depth_segmentation::CameraTracker::kImageRange));
  }

  void computeEdgeMap(const sensor_msgs::msg::Image::ConstPtr& depth_msg,
                      const sensor_msgs::msg::Image::ConstPtr& rgb_msg,
                      cv::Mat& rescaled_depth,
                      cv_bridge::CvImagePtr cv_rgb_image,
                      cv_bridge::CvImagePtr cv_depth_image, cv::Mat& bw_image,
                      cv::Mat& mask, cv::Mat* depth_map, cv::Mat* normal_map,
                      cv::Mat* edge_map) {
// #ifdef WRITE_IMAGES
//     cv::imwrite(
//         std::to_string(cv_rgb_image->header.stamp.toSec()) + "_rgb_image.png",
//         cv_rgb_image->image);
//     cv::imwrite(
//         std::to_string(cv_rgb_image->header.stamp.toSec()) + "_bw_image.png",
//         bw_image);
//     cv::imwrite(
//         std::to_string(depth_msg->header.stamp.toSec()) + "_depth_image.png",
//         rescaled_depth);
//     cv::imwrite(
//         std::to_string(depth_msg->header.stamp.toSec()) + "_depth_mask.png",
//         mask);
// #endif  // WRITE_IMAGES

// #ifdef DISPLAY_DEPTH_IMAGES
    // camera_tracker_.visualize(camera_tracker_.getDepthImage(), rescaled_depth);
// #endif  // DISPLAY_DEPTH_IMAGES

    // Compute transform from tracker.
    if (depth_segmentation::kUseTracker) {
      if (camera_tracker_.computeTransform(bw_image, rescaled_depth, mask)) {
        publish_tf(camera_tracker_.getWorldTransform(),
                   depth_msg->header.stamp);
      } else {
        LOG(ERROR) << "Failed to compute Transform.";
      }
    }

    *depth_map = cv::Mat::zeros(depth_camera_.getWidth(),
                                depth_camera_.getHeight(), CV_32FC3);
    depth_segmenter_.computeDepthMap(rescaled_depth, depth_map);

    // Compute normal map.
    *normal_map = cv::Mat::zeros(depth_map->size(), CV_32FC3);

    if (params_.normals.method ==
            depth_segmentation::SurfaceNormalEstimationMethod::kFals ||
        params_.normals.method ==
            depth_segmentation::SurfaceNormalEstimationMethod::kSri ||
        params_.normals.method ==
            depth_segmentation::SurfaceNormalEstimationMethod::
                kDepthWindowFilter) {
      depth_segmenter_.computeNormalMap(*depth_map, normal_map);
    } else if (params_.normals.method ==
               depth_segmentation::SurfaceNormalEstimationMethod::kLinemod) {
      depth_segmenter_.computeNormalMap(cv_depth_image->image, normal_map);
    }

    // Compute depth discontinuity map.
    cv::Mat discontinuity_map = cv::Mat::zeros(
        depth_camera_.getWidth(), depth_camera_.getHeight(), CV_32FC1);
    if (params_.depth_discontinuity.use_discontinuity) {
      depth_segmenter_.computeDepthDiscontinuityMap(rescaled_depth,
                                                    &discontinuity_map);
    }

    // Compute maximum distance map.
    cv::Mat distance_map = cv::Mat::zeros(depth_camera_.getWidth(),
                                          depth_camera_.getHeight(), CV_32FC1);
    if (params_.max_distance.use_max_distance) {
      depth_segmenter_.computeMaxDistanceMap(*depth_map, &distance_map);
    }

    // Compute minimum convexity map.
    cv::Mat convexity_map = cv::Mat::zeros(depth_camera_.getWidth(),
                                           depth_camera_.getHeight(), CV_32FC1);
    if (params_.min_convexity.use_min_convexity) {
      depth_segmenter_.computeMinConvexityMap(*depth_map, *normal_map,
                                              &convexity_map);
    }

    // Compute final edge map.
    *edge_map = cv::Mat::zeros(depth_camera_.getWidth(),
                               depth_camera_.getHeight(), CV_32FC1);
    depth_segmenter_.computeFinalEdgeMap(convexity_map, distance_map,
                                         discontinuity_map, edge_map);
  }

  void imageCallback(const sensor_msgs::msg::Image::ConstPtr& depth_msg,
                     const sensor_msgs::msg::Image::ConstPtr& rgb_msg) {
    if (camera_info_ready_) {
      cv_bridge::CvImagePtr cv_rgb_image(new cv_bridge::CvImage);
      cv_rgb_image = cv_bridge::toCvCopy(rgb_msg, rgb_msg->encoding);
      if (rgb_msg->encoding == sensor_msgs::image_encodings::BGR8) {
        cv::cvtColor(cv_rgb_image->image, cv_rgb_image->image, CV_BGR2RGB);
      }

      cv_bridge::CvImagePtr cv_depth_image(new cv_bridge::CvImage);
      cv::Mat rescaled_depth, dilated_rescaled_depth, bw_image, mask, depth_map,
          normal_map, edge_map;
      preprocess(depth_msg, rgb_msg, &rescaled_depth, &dilated_rescaled_depth,
                 cv_rgb_image, cv_depth_image, &bw_image, &mask);
      if (!camera_tracker_.getRgbImage().empty() &&
              !camera_tracker_.getDepthImage().empty() ||
          !depth_segmentation::kUseTracker) {
        computeEdgeMap(depth_msg, rgb_msg, dilated_rescaled_depth, cv_rgb_image,
                       cv_depth_image, bw_image, mask, &depth_map, &normal_map,
                       &edge_map);

        cv::Mat label_map(edge_map.size(), CV_32FC1);
        cv::Mat remove_no_values =
            cv::Mat::zeros(edge_map.size(), edge_map.type());
        edge_map.copyTo(remove_no_values,
                        dilated_rescaled_depth == dilated_rescaled_depth);
        edge_map = remove_no_values;
        std::vector<depth_segmentation::Segment> segments;
        std::vector<cv::Mat> segment_masks;

        depth_segmenter_.labelMap(cv_rgb_image->image, rescaled_depth,
                                  depth_map, edge_map, normal_map, &label_map,
                                  &segment_masks, &segments);

        if (segments.size() > 0u) {
          publish_segments(segments, depth_msg->header);
        }
      }
      // Update the member images to the new images.
      // TODO(ff): Consider only doing this, when we are far enough away
      // from a frame. (Which basically means we would set a keyframe.)
      depth_camera_.setImage(rescaled_depth);
      depth_camera_.setMask(mask);
      rgb_camera_.setImage(bw_image);
    }
  }

// #ifdef MASKRCNNROS_AVAILABLE
void imageSegmentationCallback(
    const sensor_msgs::msg::Image::ConstPtr& depth_msg,
    const sensor_msgs::msg::Image::ConstPtr& rgb_msg,
    const vpp_interfaces::msg::Result::ConstPtr& segmentation_msg) {
  depth_segmentation::SemanticInstanceSegmentation instance_segmentation;

  semanticInstanceSegmentationFromRosMsg(segmentation_msg, &instance_segmentation);

  if (camera_info_ready_) {
    cv_bridge::CvImagePtr cv_rgb_image(new cv_bridge::CvImage);
    cv_rgb_image = cv_bridge::toCvCopy(rgb_msg, rgb_msg->encoding);
    if (rgb_msg->encoding == sensor_msgs::image_encodings::BGR8) {
      cv::cvtColor(cv_rgb_image->image, cv_rgb_image->image, CV_BGR2RGB);
    }

    cv_bridge::CvImagePtr cv_depth_image(new cv_bridge::CvImage);
    cv::Mat rescaled_depth, dilated_rescaled_depth, bw_image, mask, depth_map,
        normal_map, edge_map;
    preprocess(depth_msg, rgb_msg, &rescaled_depth, &dilated_rescaled_depth,
                cv_rgb_image, cv_depth_image, &bw_image, &mask);
    if (!camera_tracker_.getRgbImage().empty() &&
            !camera_tracker_.getDepthImage().empty() ||
        !depth_segmentation::kUseTracker) {
      computeEdgeMap(depth_msg, rgb_msg, dilated_rescaled_depth, cv_rgb_image,
                      cv_depth_image, bw_image, mask, &depth_map, &normal_map,
                      &edge_map);

      cv::Mat label_map(edge_map.size(), CV_32FC1);
      cv::Mat remove_no_values =
          cv::Mat::zeros(edge_map.size(), edge_map.type());
      edge_map.copyTo(remove_no_values,
                      dilated_rescaled_depth == dilated_rescaled_depth);
      edge_map = remove_no_values;
      std::vector<depth_segmentation::Segment> segments;
      std::vector<cv::Mat> segment_masks;

      depth_segmenter_.labelMap(cv_rgb_image->image, rescaled_depth,
                                instance_segmentation, depth_map, edge_map,
                                normal_map, &label_map, &segment_masks,
                                &segments);

      if (segments.size() > 0u) {
        publish_segments(segments, depth_msg->header);
      }
    }

    // Update the member images to the new images.
    // TODO(ff): Consider only doing this, when we are far enough away
    // from a frame. (Which basically means we would set a keyframe.)
    depth_camera_.setImage(rescaled_depth);
    depth_camera_.setMask(mask);
    rgb_camera_.setImage(bw_image);
  }
}
// #endif

  void cameraInfoCallback(
      const sensor_msgs::msg::CameraInfo::ConstPtr& depth_camera_info_msg,
      const sensor_msgs::msg::CameraInfo::ConstPtr& rgb_camera_info_msg) {
    if (camera_info_ready_) {
      return;
    }

    sensor_msgs::msg::CameraInfo depth_info;
    depth_info = *depth_camera_info_msg;
    Eigen::Vector2d depth_image_size(depth_info.width, depth_info.height);

    cv::Mat K_depth = cv::Mat::eye(3, 3, CV_32FC1);
    K_depth.at<float>(0, 0) = depth_info.k[0];
    K_depth.at<float>(0, 2) = depth_info.k[2];
    K_depth.at<float>(1, 1) = depth_info.k[4];
    K_depth.at<float>(1, 2) = depth_info.k[5];
    K_depth.at<float>(2, 2) = depth_info.k[8];

    depth_camera_.initialize(depth_image_size.x(), depth_image_size.y(),
                             CV_32FC1, K_depth);

    sensor_msgs::msg::CameraInfo rgb_info;
    rgb_info = *rgb_camera_info_msg;
    Eigen::Vector2d rgb_image_size(rgb_info.width, rgb_info.height);

    cv::Mat K_rgb = cv::Mat::eye(3, 3, CV_32FC1);
    K_rgb.at<float>(0, 0) = rgb_info.k[0];
    K_rgb.at<float>(0, 2) = rgb_info.k[2];
    K_rgb.at<float>(1, 1) = rgb_info.k[4];
    K_rgb.at<float>(1, 2) = rgb_info.k[5];
    K_rgb.at<float>(2, 2) = rgb_info.k[8];

    rgb_camera_.initialize(rgb_image_size.x(), rgb_image_size.y(), CV_8UC1,
                           K_rgb);

    depth_segmenter_.initialize();
    camera_tracker_.initialize(
        camera_tracker_.kCameraTrackerNames
            [camera_tracker_.CameraTrackerType::kRgbdICPOdometry]);

    camera_info_ready_ = true;
  }

  void declareParameters() {
    this->declare_parameter("semantic_instance_segmentation.enable", params_.semantic_instance_segmentation.enable);
    this->declare_parameter("semantic_instance_segmentation.overlap_threshold", params_.semantic_instance_segmentation.overlap_threshold);
    this->declare_parameter("depth_image_sub_topic", depth_segmentation::kDepthImageTopic);
    this->declare_parameter("rgb_image_sub_topic", depth_segmentation::kRgbImageTopic);
    this->declare_parameter("depth_camera_info_sub_topic", depth_segmentation::kDepthCameraInfoTopic);
    this->declare_parameter("rgb_camera_info_sub_topic", depth_segmentation::kRgbCameraInfoTopic);
    this->declare_parameter("semantic_instance_segmentation_sub_topic", depth_segmentation::kSemanticInstanceSegmentationTopic);
    this->declare_parameter("world_frame", depth_segmentation::kTfWorldFrame);
    this->declare_parameter("camera_frame", depth_segmentation::kTfDepthCameraFrame);
    this->declare_parameter("visualize_segmented_scene", params_.visualize_segmented_scene);
  }
};

int main(int argc, char** argv) {
  depth_segmentation::Params debugParams;
  std::cout << "Debug param dilation size: " << debugParams.dilation_size << std::endl;

  google::InitGoogleLogging(argv[0]);
  FLAGS_stderrthreshold = 0;
  LOG(INFO) << "Starting depth segmentation ... ";

  rclcpp::init(argc, argv);
  auto node = std::make_shared<DepthSegmentationNode>();

  // Sets up a dynamic reconfigure server
  // dynamic_reconfigure::Server<depth_segmentation::DepthSegmenterConfig> reconfigure_server;
  // dynamic_reconfigure::Server<depth_segmentation::DepthSegmenterConfig>::CallbackType dynamic_reconfigure_function;

  // dynamic_reconfigure_function = std::bind(
  //     &depth_segmentation::DepthSegmenter::dynamicReconfigureCallback, &depth_segmentation_node.depth_segmenter_, _1, _2);

  // reconfigure_server.setCallback(dynamic_reconfigure_function);

  rclcpp::spin(node);
  rclcpp::shutdown();
  return EXIT_SUCCESS;
}
