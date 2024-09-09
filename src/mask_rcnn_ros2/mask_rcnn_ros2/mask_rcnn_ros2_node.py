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
from rclpy.executors import MultiThreadedExecutor

import multiprocessing as mp
import numpy as np
import os
import time
import cv2
from cv_bridge import CvBridge
import math

import torch
from torch import Tensor
from torchvision import transforms as T

from detectron2.config import get_cfg
from detectron2.data.detection_utils import read_image
from detectron2.utils.logger import setup_logger
from detectron2.utils.visualizer import VisImage

from mask_rcnn_ros2.predictor import VisualizationDemo as MaskRCNN
from vpp_interfaces.msg import Result
    
from camera.camera_zed import CAMERA_FPS

# constants
WINDOW_NAME = "COCO detections"
ROS_HOME = os.environ.get('ROS_HOME', os.path.join(os.environ['HOME'], '.ros'))
# RGB_TOPIC = '/camera/rgb/image_raw'
CONFIG_FILE = '/home/alpha/Research/voxblox/src/mask_rcnn_ros2/configs/COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x.yaml'
COCO_MODEL_PATH = 'detectron2://COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x/138205316/model_final_a3ec72.pkl'
CONFIDENCE_THRESHOLD = 0.5

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



class MaskRCNNNode(Node):
    def __init__(self):
        super().__init__('mask_rcnn_node', namespace='mask_rcnn')
        self._cv_bridge = CvBridge()
        self._cfg = self.setup_cfg()
        self._predict = MaskRCNN(self._cfg, parallel=True)
        
        self.size = [512, 928, 3] # Inference image size [H, W, C]
        self.predictions = None
        self.visualized_output = np.zeros(self.size, dtype=np.uint8)
        
        qos_profile = QoSProfile(depth=50) # Here 50 is optimal for zed camera
        # self.timer =  self.create_timer(0.5/CAMERA_FPS, self._handel_publish_image) # TODO Why 0.5/CAMERA_FPS would be so much faster than 1/CAMERA_FPS?
        
        self._image_sub = self.create_subscription(Image, '/camera/rgb_image', self._handle_process_image, qos_profile) # Subscribe to topic 'image_raw'
        # self._result_pub = self.create_publisher(Result, 'result', 1) # Publish result_msg to topic 'result'
        self._vis_pub = self.create_publisher(Image, 'vis', 10)
        
        self.get_logger().info('Mask R-CNN Node has been started.')
    
    def _handle_process_image(self, msg):
        self.get_logger().info('Received an image, processing...')
        
        bgr_image = self._cv_bridge.imgmsg_to_cv2(msg, 'bgr8') # Convert image message to numpy tensor
        bgr_image = self.preprocess(bgr_image) # Scale and resize the image
        
        predictions, self.visualized_output = self._predict.run_on_image(bgr_image) # The images here should be in BGR format
        return
    
    def _handel_publish_image(self):
        print('Publishing image...')
        # start = time.time()
        image_msg = self._cv_bridge.cv2_to_imgmsg(self.visualized_output, 'bgr8')
        # self._vis_pub.publish(image_msg)
        
        # result_msg = self._build_result_msg(msg.header, predictions)
        # self._result_pub.publish(result_msg)
        # print("single image pub time: ", time.time() - start)
        
    def preprocess(self, image):
        image = torch.from_numpy(image).permute(2, 0, 1).to('cuda')
        H, W = image.shape[1:]
        scale_factor = self.size[0] / min(H, W) # Scale 
        nH, nW = round(H*scale_factor), round(W*scale_factor) # newHight and newWidth
        nH, nW = int(math.ceil(nH / 32)) * 32, int(math.ceil(nW / 32)) * 32 # Round to nearest 32
        image = T.Resize((nH, nW))(image) #Adjust the image size according to the nH and nW
        image = image.to("cpu").permute(1, 2, 0).numpy()
        return image
    
    def setup_cfg(self):
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
    
    def _build_result_msg(self, header, predictions):
        result_msg = Result()
        result_msg.header = header
        instances = predictions["instances"].to("cpu") #to("cpu") is used to move the tensor to cpu

        class_ids = instances.pred_classes.tolist()
        scores = instances.scores.tolist()
        boxes = instances.pred_boxes
        masks = instances.pred_masks
        
        result_msg.class_ids = class_ids
        result_msg.class_names = [CLASS_NAMES[i] for i in class_ids]
        result_msg.scores = scores
        
        for i, box in enumerate(boxes):
            result_box = RegionOfInterest()
            result_box.x_offset = int(box[0])
            result_box.y_offset = int(box[1])
            result_box.height = int(box[3] - box[1])
            result_box.width = int(box[2] - box[0])
            result_msg.boxes.append(result_box)
            
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
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    
    # rclpy.spin(node)
    executor.spin()
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()  # pragma: no cover
