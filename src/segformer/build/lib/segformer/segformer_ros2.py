import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

import re
import torch
import argparse
import yaml
import math
import numpy as np

from torch import Tensor
from torch.nn import functional as F
from pathlib import Path
from torchvision import io
from torchvision import transforms as T

from semantic_segmentation.semseg.models import *
from semantic_segmentation.semseg.datasets import *
from semantic_segmentation.semseg.utils.utils import timer
from semantic_segmentation.semseg.utils.visualize import draw_text

from rich.console import Console

import ros2_numpy

console = Console()

class SemSeg(Node):
    def __init__(self, cfg):
        super().__init__('semseg_node')
        self.cfg = cfg
        self.device = torch.device(self.cfg['DEVICE'])
        self.seg_publisher_ = self.create_publisher(Image, "/segnet/color_mask", 10)
        self.bridge_ = CvBridge()
        self.palette = eval(self.cfg['DATASET']['NAME']).PALETTE
        self.labels = eval(self.cfg['DATASET']['NAME']).CLASSES

        self.cfg['TEST']['MODEL_PATH'] = '/home/alpha/Research/voxblox/checkpoints/pretrained/segformer/segformer.b2.ade.pth'
        self.model = eval(self.cfg['MODEL']['NAME'])(self.cfg['MODEL']['BACKBONE'], len(self.palette))
        self.model.load_state_dict(torch.load(self.cfg['TEST']['MODEL_PATH'], map_location='cpu'))
        self.model = self.model.to(self.device)
        self.model.eval()

        self.size = self.cfg['TEST']['IMAGE_SIZE']
        self.tf_pipeline = T.Compose([
            T.Lambda(lambda x: x / 255),
            T.Normalize((0.485, 0.456, 0.406), (0.229, 0.224, 0.225)),
            T.Lambda(lambda x: x.unsqueeze(0))
        ])

        self.subscription = self.create_subscription(
            Image,
            "/camera/image_raw",
            self.segformer_callback,
            10)
        self.subscription

    def preprocess(self, image: Tensor) -> Tensor:
        H, W = image.shape[1:]
        console.print(f"Original Image Size > [red]{H}x{W}[/red]")
        scale_factor = self.size[0] / min(H, W)
        nH, nW = round(H*scale_factor), round(W*scale_factor)
        nH, nW = int(math.ceil(nH / 32)) * 32, int(math.ceil(nW / 32)) * 32
        console.print(f"Inference Image Size > [red]{nH}x{nW}[/red]")
        image = T.Resize((nH, nW))(image)
        image = self.tf_pipeline(image).to(self.device)
        return image

    def postprocess(self, orig_img: Tensor, seg_map: Tensor, overlay: bool) -> Tensor:
        seg_map = F.interpolate(seg_map, size=orig_img.shape[-2:], mode='bilinear', align_corners=True)
        seg_map = seg_map.softmax(dim=1).argmax(dim=1).cpu().to(int)
        seg_image = self.palette[seg_map].squeeze()
        return seg_image

    @torch.inference_mode()
    @timer
    def model_forward(self, img: Tensor) -> Tensor:
        return self.model(img)
        
    def predict(self, image: Tensor, overlay: bool) -> Tensor:
        img = self.preprocess(image)
        seg_map = self.model_forward(img)
        seg_map = self.postprocess(image, seg_map, overlay)
        seg_map = np.uint8(seg_map.numpy())
        return seg_map

    def segformer_callback(self, rgb_msg):
        try:
            rgb_img = ros2_numpy.numpify(rgb_msg)[:,:,0:3]
            rgb_img = torch.tensor(rgb_img).to(self.device).permute(2,0,1)
        except CvBridgeError as e:
            self.get_logger().error(f"CV Bridge Error: {e}")

        with console.status("[bright_green]Processing..."):
            segmap = self.predict(rgb_img, self.cfg['TEST']['OVERLAY'])
            seg_msg = self.bridge_.cv2_to_imgmsg(segmap, encoding="rgb8")
            seg_msg.header.stamp = self.get_clock().now().to_msg()

            self.seg_publisher_.publish(seg_msg)

def main(args=None):
    rclpy.init(args=args)

    parser = argparse.ArgumentParser()
    parser.add_argument('--cfg', type=str, default='/home/alpha/Research/voxblox/src/segformer/semantic_segmentation/configs/ade20k.yaml')
    args = parser.parse_args()

    with open(args.cfg) as f:
        cfg = yaml.load(f, Loader=yaml.SafeLoader)

    console.print(f"Model > [red]{cfg['MODEL']['NAME']} {cfg['MODEL']['BACKBONE']}[/red]")
    console.print(f"Model > [red]{cfg['DATASET']['NAME']}[/red]")

    semseg_node = SemSeg(cfg)

    rclpy.spin(semseg_node)

    semseg_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()