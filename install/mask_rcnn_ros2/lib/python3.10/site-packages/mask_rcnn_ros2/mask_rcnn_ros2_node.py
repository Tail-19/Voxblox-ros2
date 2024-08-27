#!/usr/bin/env python
import os
import sys
import threading

#ROS
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from sensor_msgs.msg import RegionOfInterest
from rclpy.qos import QoSProfile

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
from vpp_interfaces.msg import Result\
    
from camera.camera_zed import CAMERA_FPS

# constants
WINDOW_NAME = "COCO detections"
ROS_HOME = os.environ.get('ROS_HOME', os.path.join(os.environ['HOME'], '.ros'))
# COCO_MODEL_PATH = os.path.join(ROS_HOME, 'mask_rcnn_coco.h5')
# RGB_TOPIC = '/camera/rgb/image_raw'
CONFIG_FILE = '/home/alpha/Research/voxblox/src/mask_rcnn_ros2/configs/COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x.yaml'
CONFIDENCE_THRESHOLD = 0.5
COCO_MODEL_PATH = 'detectron2://COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x/138205316/model_final_a3ec72.pkl'

CLASS_NAMES = ['BG', 'person', 'bicycle', 'car', 'motorcycle', 'airplane',
               'bus', 'train', 'truck', 'boat', 'traffic light',
               'fire hydrant', 'stop sign', 'parking meter', 'bench', 'bird',
               'cat', 'dog', 'horse', 'sheep', 'cow', 'elephant', 'bear',
               'zebra', 'giraffe', 'backpack', 'umbrella', 'handbag', 'tie',
               'suitcase', 'frisbee', 'skis', 'snowboard', 'sports ball',
               'kite', 'baseball bat', 'baseball glove', 'skateboard',
               'surfboard', 'tennis racket', 'bottle', 'wine glass', 'cup',
               'fork', 'knife', 'spoon', 'bowl', 'banana', 'apple',
               'sandwich', 'orange', 'broccoli', 'carrot', 'hot dog', 'pizza',
               'donut', 'cake', 'chair', 'couch', 'potted plant', 'bed',
               'dining table', 'toilet', 'tv', 'laptop', 'mouse', 'remote',
               'keyboard', 'cell phone', 'microwave', 'oven', 'toaster',
               'sink', 'refrigerator', 'book', 'clock', 'vase', 'scissors',
               'teddy bear', 'hair drier', 'toothbrush']

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

class MaskRCNNNode(Node):
    def __init__(self):
        super().__init__('mask_rcnn_node', namespace='mask_rcnn')
        self._cv_bridge = CvBridge()
        self._cfg = setup_cfg()
        self._predict = MaskRCNN(self._cfg, parallel=True)
        
        qos_profile = QoSProfile(depth=50) # Here 50 is optimal for zed camera
        self._result_sub = self.create_subscription(Image, '/camera/image_raw', self._handle_process_image, qos_profile) #subscribe to topic 'image_raw'
        self._result_pub = self.create_publisher(Result, 'result', 1) # Publish result_msg to topic 'result'
        self._vis_pub = self.create_publisher(Image, 'visualization', 1)
        
        self.get_logger().info('Mask R-CNN Node has been started.')
        
    # def _handle_multithread(self,  msg):
    #     if len(self.threads) < 3:
    #         t = threading.Thread(target=self._handle_process_image, args=(msg,))
    #         t.start()
    #         self.threads.append(t)
    
    def _handle_process_image(self, msg):
        self.get_logger().info('Received an image, processing...')
        bgr_image = self._cv_bridge.imgmsg_to_cv2(msg, 'bgr8') #convert image message to numpy tensor
        
        self.get_logger().info(str(bgr_image.shape))
        
        start = time.time()
        predictions, visualized_output = self._predict.run_on_image(bgr_image) #the images here should be in BGR format

        print("single image publish time: ", time.time() - start)
        image_msg = self._cv_bridge.cv2_to_imgmsg(visualized_output.get_image(), 'bgr8')
        self._vis_pub.publish(image_msg)
        result_msg = self._build_result_msg(msg.header, predictions)
        self._result_pub.publish(result_msg)
        
        return
    
    def _build_result_msg(self, header, predictions):
        result_msg = Result()
        result_msg.header = header
        instances = predictions["instances"].to("cpu") #to("cpu") is used to move the tensor to cpu
        boxes = instances.pred_boxes if instances.has("pred_boxes") else None
        scores = instances.scores if instances.has("scores") else None
        classes = instances.pred_classes if instances.has("pred_classes") else None
        masks = instances.pred_masks if instances.has("pred_masks") else None
        
        result_msg.class_ids = classes.tolist()
        result_msg.class_names = [CLASS_NAMES[i] for i in classes.tolist()]
        result_msg.scores = scores.tolist()
        
        for box in boxes:
            result_box = RegionOfInterest()
            result_box.x_offset = int(box[0])
            result_box.y_offset = int(box[1])
            result_box.height = int(box[3] - box[1])
            result_box.width = int(box[2] - box[0])
            result_msg.boxes.append(result_box)
            
        #TODO 这里需要改一下，mask现在输出的不是个矩阵
        for i in range(masks.shape[0]):
            result_mask = Image()
            result_mask.header = header
            result_mask.height = int(masks[i].shape[0])
            result_mask.width = int(masks[i].shape[1])
            result_mask.encoding = "mono8"
            result_mask.is_bigendian = False
            result_mask.step = int(result_mask.width)
            result_mask.data = (masks.numpy() * 255).astype(np.uint8).tobytes()
            result_msg.masks.append(result_mask)
        
        return result_msg
    
def main():
    rclpy.init()
    node = MaskRCNNNode()
    
    rclpy.spin(node)
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()  # pragma: no cover
