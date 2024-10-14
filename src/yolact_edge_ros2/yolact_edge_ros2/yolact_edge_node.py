#!/usr/bin/env python
import os
import sys
import threading

#ROS
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from sensor_msgs.msg import RegionOfInterest
from rclpy.qos import QoSProfile, ReliabilityPolicy
from rclpy.executors import MultiThreadedExecutor
# from rclpy import rmw

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

from vpp_interfaces.msg import Result
    
from camera.camera_zed import CAMERA_FPS

from model import eval



COCO_CLASSES = ('person', 'bicycle', 'car', 'motorcycle', 'airplane', 'bus',
                'train', 'truck', 'boat', 'traffic light', 'fire hydrant',
                'stop sign', 'parking meter', 'bench', 'bird', 'cat', 'dog',
                'horse', 'sheep', 'cow', 'elephant', 'bear', 'zebra', 'giraffe',
                'backpack', 'umbrella', 'handbag', 'tie', 'suitcase', 'frisbee',
                'skis', 'snowboard', 'sports ball', 'kite', 'baseball bat',
                'baseball glove', 'skateboard', 'surfboard', 'tennis racket',
                'bottle', 'wine glass', 'cup', 'fork', 'knife', 'spoon', 'bowl',
                'banana', 'apple', 'sandwich', 'orange', 'broccoli', 'carrot',
                'hot dog', 'pizza', 'donut', 'cake', 'chair', 'couch',
                'potted plant', 'bed', 'dining table', 'toilet', 'tv', 'laptop',
                'mouse', 'remote', 'keyboard', 'cell phone', 'microwave', 'oven',
                'toaster', 'sink', 'refrigerator', 'book', 'clock', 'vase',
                'scissors', 'teddy bear', 'hair drier', 'toothbrush')


class YolactEdgeNode(Node):
    def __init__(self):
        super().__init__('yolact_edge_node', namespace='instance_seg')
        self._cv_bridge = CvBridge()
        self._args = self._setup_args()
        self._model = self._get_model(self._args)
        
        self.size = [480, 640, 3] # Inference image size [H, W, C]
        self.prediction = None
        self.visualized_output = np.zeros(self.size, dtype=np.uint8)
        self.msg = Image()
        
        qos_profile = QoSProfile(depth=1, reliability=ReliabilityPolicy.RELIABLE) # Here 50 is optimal for zed camera
        
        self._image_sub = self.create_subscription(Image, '/camera/rgb_image', self._handle_process_image, qos_profile) # '/zed/zed_node/rgb/image_rect_color'
        
        # self._debug_timer = self.create_timer(0.5/CAMERA_FPS, self._debug)
        self._debug_pub = self.create_publisher(Image, 'debug', qos_profile)
        
        self._timer_vis =  self.create_timer(0.5/CAMERA_FPS, self._handle_publish_image) # TODO Why 0.5/CAMERA_FPS would be so much faster than 1/CAMERA_FPS?
        self._timer_result = self.create_timer(0.5/CAMERA_FPS, self._handle_publish_result)
        self._result_pub = self.create_publisher(Result, 'result', 1) # Publish result_msg to topic 'result'
        self._vis_pub = self.create_publisher(Image, 'vis', qos_profile)
        
        self.get_logger().info('Yolact-edge Node has been started.')
        
        self.received = False
        
    def _debug(self):
        self._debug_pub.publish(self.msg)
    
    def _handle_process_image(self, msg):
        self.get_logger().info('Received an image, processing...')
        start = time.time()
        self.msg = msg
        self.received = True
        bgr_image = self._cv_bridge.imgmsg_to_cv2(msg, 'bgr8') # Convert image message to numpy tensor
        bgr_image = self._preprocess(bgr_image) # Scale and resize the image
        rgb_image = cv2.cvtColor(bgr_image, cv2.COLOR_BGR2RGB) # Convert BGR to RGB
        
        self.prediction, self.visualized_output = self._predict(rgb_image) # The images here should be in RGB format
        self.get_logger().info(f'Processing time: {time.time() - start}')
        return
    
    def _handle_publish_image(self):
        if self.received == False:
            return
        
        print('Publishing image...')
        self._vis_pub.publish(self._cv_bridge.cv2_to_imgmsg(self.visualized_output, 'bgr8'))
        self.received = False
        
    def _handle_publish_result(self):    
        if self.prediction is None:
            return
        result_msg = self._build_result_msg()
        self._result_pub.publish(result_msg)
        
    def _preprocess(self, image) -> np.ndarray:  
        image = torch.from_numpy(image).permute(2, 0, 1).to('cuda')
        H, W = image.shape[1:]
        scale_factor = self.size[0] / min(H, W) # Scale 
        nH, nW = round(H*scale_factor), round(W*scale_factor) # newHight and newWidth
        nH, nW = int(math.ceil(nH / 32)) * 32, int(math.ceil(nW / 32)) * 32 # Round to nearest 32
        image = T.Resize((nH, nW))(image) #Adjust the image size according to the nH and nW
        image = image.to("cpu").permute(1, 2, 0).numpy()
        return image
    
    def _post_process(self):
        classes, scores, boxes, masks = \
                eval.postprocess(self.prediction, self.size[0], self.size[1], \
                    crop_masks=self._args.crop, score_threshold=self._args.score_threshold)
        return classes, scores, boxes, masks
    
    def _setup_args(self):
        args = eval.parse_args()
        args.score_threshold = 0.2
        args.top_k = 100
        args.image = 'use image' # 这里的实现不太优雅，后面改一下
        args.disable_tensorrt = True
        args.use_fp16_tensorrt = True
        args.trained_model = '/home/alpha/Research/voxblox/checkpoints/pretrained/yolact_edge/yolact_edge_54_800000.pth'
        return args
    
        #get a model that reviece image and return prediction and visualized_output
    def _get_model(self, args):
        return eval.get_yolact_edge_model(args)
    
    #image numpy-->prediction, vis
    def _predict(self, image):
        with torch.no_grad():
            return eval.run_on_image(net=self._model, image=image)
    
    def _build_result_msg(self):
        result_msg = Result()
        result_msg.header = self.msg.header
        class_ids, scores, boxes, masks = self._post_process()

        result_msg.class_ids = class_ids.to('cpu').numpy().tolist()
        result_msg.class_names = [COCO_CLASSES[id] for id in result_msg.class_ids]
        result_msg.scores = scores.to('cpu').numpy().tolist()
        
        print(result_msg.class_names)
                
        boxes = boxes.to('cpu').numpy()
        masks = masks.to('cpu').numpy()

        for i in range(min(masks.shape[0], boxes.shape[0])):
            if (boxes[i, 3] - boxes[i, 1]) > 0 and (boxes[i, 2] - boxes[i, 0]) > 0:
                result_box = RegionOfInterest()
                print(boxes[i, :])
                result_box.x_offset = int(boxes[i, 0])
                result_box.y_offset = int(boxes[i, 1])
                result_box.height = int(boxes[i, 3] - boxes[i, 1])
                result_box.width = int(boxes[i, 2] - boxes[i, 0])
                result_msg.boxes.append(result_box)

                result_mask = Image()
                result_mask.header = self.msg.header
                result_mask.height = int(masks.shape[0])
                result_mask.width = int(masks.shape[1])
                result_mask.encoding = "mono8"
                result_mask.is_bigendian = False
                result_mask.step = result_mask.width
                result_mask.data = (masks[:, :, i]* 255).astype(np.uint8).tobytes()
                result_msg.masks.append(result_mask)
        
        return result_msg
    
    
def main():
    rclpy.init()
    # print(rmw.implementation_identifier())
    node = YolactEdgeNode()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    
    rclpy.spin(node)
    executor.spin()
    
    
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()  # pragma: no cover
