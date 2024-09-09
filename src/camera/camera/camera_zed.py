# ROS
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from rclpy.qos import QoSProfile, ReliabilityPolicy

# OpenCV
from cv_bridge import CvBridge
import cv2

# ZED
import pyzed.sl as sl

import numpy as np

CAMERA_FPS = 20

# This class supports publish and request for ZED camera
class CameraZed(Node):
    def __init__(self):
        super().__init__('camera_zed', namespace='camera')
        qos_profile = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE) 
        # Publishers Depth的相机信息暂时没有发布，因为目前判断和RGB相机信息一样
        self.timer = self.create_timer(1/CAMERA_FPS, self.timer_callback)
        self._publisher_rgb_image = self.create_publisher(Image, 'rgb_image', qos_profile)
        self._publisher_rgb_camera_info = self.create_publisher(CameraInfo, 'rgb_camera_info', qos_profile)
        self._publisher_depth_image = self.create_publisher(Image, 'depth_image', qos_profile)
        # self._publisher_depth_camera_info = self.create_publisher(CameraInfo, 'depth_camera_info', 10)
        
        self.init_camera()
        
        # For image processing
        self.bridge = CvBridge()
        
    def init_camera(self):
        self.zed = sl.Camera()
        init_params = sl.InitParameters()
        init_params.camera_resolution = sl.RESOLUTION.HD1080 # Use HD720 opr HD1200 video mode, depending on camera type.
        init_params.depth_mode = sl.DEPTH_MODE.PERFORMANCE
        # Use ULTRA depth mode
        init_params.coordinate_units = sl.UNIT.MILLIMETER  # Use meter units (for depth measurements)

        status = self.zed.open(init_params)
        if status != sl.ERROR_CODE.SUCCESS:
            self.get_logger().error(f'Failed to open ZED camera: {status}')
            rclpy.shutdown()

        self.runtime_parameters = sl.RuntimeParameters()
        self.mat_rgb = sl.Mat()
        self.mat_depth = sl.Mat()

    def timer_callback(self):
        if self.zed.grab(self.runtime_parameters) == sl.ERROR_CODE.SUCCESS:
            self.zed.retrieve_image(self.mat_rgb, sl.VIEW.LEFT)
            self.zed.retrieve_measure(self.mat_depth, sl.MEASURE.DEPTH)

            rgb_image = self.mat_rgb.get_data()
            depth_image = self.mat_depth.get_data().astype(np.float32)

            # Publish RGB image
            rgb_msg = self.bridge.cv2_to_imgmsg(rgb_image, encoding='bgra8')
            rgb_msg.header.stamp = self.get_clock().now().to_msg()
            self._publisher_rgb_image.publish(rgb_msg)

            # Publish depth image
            depth_msg = self.bridge.cv2_to_imgmsg(depth_image, encoding='32FC1')
            depth_msg.header.stamp = self.get_clock().now().to_msg()
            self._publisher_depth_image.publish(depth_msg)
            
            camera_info = self.zed.get_camera_information().camera_configuration.calibration_parameters

            # Publish RGB camera info
            rgb_cam_info_msg = CameraInfo()
            rgb_cam_info_msg.header.stamp = self.get_clock().now().to_msg()
            rgb_cam_info_msg.width = rgb_image.shape[1]
            rgb_cam_info_msg.height = rgb_image.shape[0]
            rgb_cam_info_msg.distortion_model = 'plumb_bob'
            rgb_cam_info_msg.d = camera_info.left_cam.disto.tolist()
                
            # Intrinsic camera matrix (K)
            rgb_cam_info_msg.k = list(map(float, [
                camera_info.left_cam.fx, 0, camera_info.left_cam.cx,
                0, camera_info.left_cam.fy, camera_info.left_cam.cy,
                0, 0, 1
            ]))
            # Rectification matrix (R) - Identity if no rectification
            rgb_cam_info_msg.r = list(map(float, [
                1, 0, 0,
                0, 1, 0,
                0, 0, 1
            ]))
            # Projection/camera matrix (P)
            tx = camera_info.stereo_transform.get_translation().get()[0]
            rgb_cam_info_msg.p = list(map(float, [
                camera_info.left_cam.fx, 0, camera_info.left_cam.cx, -tx * camera_info.left_cam.fx,
                0, camera_info.left_cam.fy, camera_info.left_cam.cy, 0,
                0, 0, 1, 0
            ]))
            
            self._publisher_rgb_camera_info.publish(rgb_cam_info_msg)
            
            self.get_logger().info("Publishing ZED image frame, wait for image processing...")

        
def main(args=None):
    rclpy.init(args=args)

    camera_zed = CameraZed()

    rclpy.spin(camera_zed)

    camera_zed.destroy_node()
    rclpy.shutdown()

if __name__== '__main__':
    main()