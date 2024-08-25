#!/usr/bin/env python
import os
import sys

curPath = os.path.abspath(os.path.dirname(__file__))
print(curPath)
rootPath = os.path.split(curPath)[0]
print(rootPath)
sys.path.append(rootPath)

#ROS
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from sensor_msgs.msg import RegionOfInterest

import multiprocessing as mp
import numpy as np
import os
import time
import cv2
from cv_bridge import CvBridge

from detectron2.config import get_cfg
from detectron2.data.detection_utils import read_image
from detectron2.utils.logger import setup_logger

from mask_rcnn_ros2.predictor import VisualizationDemo as MaskRCNN
from vpp_interfaces.msg import Result
from vpp_interfaces.srv import PredictRGB

# constants
WINDOW_NAME = "COCO detections"
ROS_HOME = os.environ.get('ROS_HOME', os.path.join(os.environ['HOME'], '.ros'))
# COCO_MODEL_PATH = os.path.join(ROS_HOME, 'mask_rcnn_coco.h5')
# RGB_TOPIC = '/camera/rgb/image_raw'
CONFIG_FILE = '/home/alpha/Research/voxblox/src/mask_rcnn_ros2/configs/COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x.yaml'
CONFIDENCE_THRESHOLD = 0.5
COCO_MODEL_PATH = 'detectron2://COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x/138205316/model_final_a3ec72.pkl'

def setup_cfg():
    # load config from file and command-line arguments
    cfg = get_cfg()
    cfg.merge_from_file(CONFIG_FILE)
    # Set score_threshold for builtin models
    cfg.MODEL.RETINANET.SCORE_THRESH_TEST = CONFIDENCE_THRESHOLD
    cfg.MODEL.ROI_HEADS.SCORE_THRESH_TEST = CONFIDENCE_THRESHOLD
    cfg.MODEL.PANOPTIC_FPN.COMBINE.INSTANCES_CONFIDENCE_THRESH = CONFIDENCE_THRESHOLD
    cfg.MODEL.WEIGHTS = COCO_MODEL_PATH
    cfg.freeze()
    return cfg

#subscribe RGBTOPIC
#publish result_msg image_msg 

class MaskRCNNNode(Node):
    def __init__(self):
        super().__init__('mask_rcnn_node')
        self._cv_bridge = CvBridge()
        self._cfg = setup_cfg()
        self._predict = MaskRCNN(self._cfg, parallel=True)
        self._result_sub = self.create_subscription(Image, '/zed/zed_node/rgb/image_rect_color', self._handle_process_image, 10) #subscribe to topic 'image_raw'
        self._result_pub = self.create_publisher(Result, 'result', 10) #publish result_msg to topic 'result'
        self._vis_pub = self.create_publisher(Image, 'visualization', 10)
        self._vis_pub_debug = self.create_publisher(Image, 'debug', 10)
        self.get_logger().info('Mask R-CNN Node has been started.')
        
    def _handle_process_image(self, msg):
        # self.get_logger().info('Received an image, processing...')
        bgr_image = self._cv_bridge.imgmsg_to_cv2(msg, 'bgr8') #convert image message to numpy tensor
        # bgr_image = cv2.cvtColor(bgra_image, cv2.COLOR_BGRA2BGR)
        start = time.time()
        predictions, visualized_output = self._predict.run_on_image(bgr_image) #the images here should be in BGR format
        print("single image inference time: ", time.time() - start)
        self.get_logger().info(str(visualized_output.get_image().shape))
        cv2.namedWindow(WINDOW_NAME, cv2.WINDOW_NORMAL)
        cv2.imshow(WINDOW_NAME, visualized_output.get_image()) 
        cv2.waitKey(0)
        
        image_msg = self._cv_bridge.cv2_to_imgmsg(visualized_output.get_image(), 'bgr8')
        self._vis_pub.publish(image_msg)
        
        # result_msg = self._build_result_msg(msg.header, predictions)
        # self._result_pub.publish(result_msg)

        # image_msg = self._cv_bridge.cv2_to_imgmsg(visualized_output.get_image()[:, :, ::-1], 'bgr8')
        # self._vis_pub.publish(image_msg)

        return
    
    def _build_result_msg(self, header, predictions):
        result_msg = Result()
        result_msg.header = header
        instances = predictions["instances"].to("cpu")
        boxes = instances.pred_boxes if instances.has("pred_boxes") else None
        scores = instances.scores if instances.has("scores") else None
        classes = instances.pred_classes if instances.has("pred_classes") else None
        masks = instances.pred_masks if instances.has("pred_masks") else None

        for i in range(len(boxes)):
            box = RegionOfInterest()
            box.x_offset = int(boxes[i][0])
            box.y_offset = int(boxes[i][1])
            box.height = int(boxes[i][3] - boxes[i][1])
            box.width = int(boxes[i][2] - boxes[i][0])
            result_msg.boxes.append(box)
            result_msg.class_ids.append(int(classes[i]))
            result_msg.scores.append(float(scores[i]))

            mask = Image()
            mask.header = header
            mask.height = masks[i].shape[0]
            mask.width = masks[i].shape[1]
            mask.encoding = "mono8"
            mask.is_bigendian = False
            mask.step = mask.width
            mask.data = (masks[i].numpy() * 255).astype(np.uint8).tobytes()
            result_msg.masks.append(mask)

        return result_msg
    
def main():
    rclpy.init()
    node = MaskRCNNNode()
    
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

# def main() -> None: #-> None is a type hint, it means that the function returns None
#     mp.set_start_method("spawn", force=True) #spawn is the default method, it creates a new process and runs the code

#     setup_logger(name="fvcore")
#     logger = setup_logger()

#     cfg = setup_cfg()

#     demo = MaskRCNN(cfg)
#     path = "image1.jpeg"

#     # use PIL, to be consistent with evaluation
#     img = read_image(path, format="BGR")
#     start_time = time.time()
#     predictions, visualized_output = demo.run_on_image(img)

#     cv2.namedWindow(WINDOW_NAME, cv2.WINDOW_NORMAL)
#     cv2.imshow(WINDOW_NAME, visualized_output.get_image()[:, :, ::-1])
#     cv2.waitKey(0)
        

if __name__ == "__main__":
    main()  # pragma: no cover
