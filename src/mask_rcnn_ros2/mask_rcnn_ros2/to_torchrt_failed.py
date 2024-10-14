import atexit
import bisect
import multiprocessing as mp
from collections import deque
import cv2
import torch
print(torch.cuda.is_available())
print(torch.__version__)
from torch import tensor
import onnx
import io
import numpy as np

import tensorrt as trt
import pycuda.driver as cuda
import pycuda.autoinit

from detectron2.data import MetadataCatalog
from detectron2.engine.defaults import DefaultPredictor
from detectron2.utils.video_visualizer import VideoVisualizer
from detectron2.utils.visualizer import ColorMode, Visualizer
from detectron2.config import get_cfg
import detectron2.data.transforms as T
import time
import os

CONFIG_FILE = '/home/alpha/Research/voxblox/src/mask_rcnn_ros2/configs/COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x.yaml'
COCO_MODEL_PATH = 'detectron2://COCO-InstanceSegmentation/mask_rcnn_R_101_FPN_3x/138205316/model_final_a3ec72.pkl'
CONFIDENCE_THRESHOLD = 0.5
ONNX_FILE_PATH = "~/Research/voxblox/onnx/maskrcnn.onnx"
TRT_LOGGER = trt.Logger(trt.Logger.WARNING)

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


# class ONNX_DefaultPredictor:
#     def __init__(self, cfg):
#         print("ONNX Default Predictor")
#         self.cfg = cfg
#         self.predictor = DefaultPredictor(cfg)
#         self.size = [512, 928, 3] # Inference image size [H, W, C]
#         self.model = self.predictor.model
#         self.model.eval()
#         self.engine = self.default_predictor_to_onnx()
#         print("ONNX Default Predictor Built")

#     def default_predictor_to_onnx(self):
#         onnx_file_path = self.export_onnx_model(ONNX_FILE_PATH)
#         engine = self.build_engine(onnx_file_path)
#         return engine

#     def export_onnx_model(self, onnx_file_path = 'None'):
#         if os.path.exists(onnx_file_path):
#             print(f"ONNX 模型已存在于 {onnx_file_path}")
#             return onnx_file_path
        
#         sample_input = torch.from_numpy(np.random.rand(512, 928, 3).astype(np.float32)) #H, W, C
#         # 导出模型 
#         onnx_program = torch.onnx.dynamo_export(self.model, sample_input)
#         print(f"ONNX 模型已导出到 {onnx_file_path}")
#         return onnx_file_path
        
#     def build_engine(self, onnx_file_path):
#         """构建 TensorRT 引擎"""
#         with trt.Builder(TRT_LOGGER) as builder, builder.create_network(1) as network, trt.OnnxParser(network, TRT_LOGGER) as parser:
#             builder.max_workspace_size = 2 << 30  
#             builder.max_batch_size = 1 

#             # 读取 ONNX 模型文件
#             with open(onnx_file_path, 'rb') as model:
#                 parser.parse(model.read())

#             # 构建 TensorRT 引擎
#             engine = builder.build_cuda_engine(network)
#             return engine

#     def infer_with_tensorrt(self, input_data):
#         """使用 TensorRT 引擎进行推理"""
#         # 分配缓冲区
#         h_input = cuda.pagelocked_empty(trt.volume(self.engine.get_binding_shape(0)), dtype=np.float32)
#         h_output = cuda.pagelocked_empty(trt.volume(self.engine.get_binding_shape(1)), dtype=np.float32)
#         d_input = cuda.mem_alloc(h_input.nbytes)
#         d_output = cuda.mem_alloc(h_output.nbytes)

#         # 创建流
#         stream = cuda.Stream()

#         # 将输入数据复制到设备
#         cuda.memcpy_htod_async(d_input, input_data, stream)

#         # 执行推理
#         context = self.engine.create_execution_context()
#         context.execute_async(bindings=[int(d_input), int(d_output)], stream_handle=stream.handle)

#         # 将结果复制回主机
#         cuda.memcpy_dtoh_async(h_output, d_output, stream)
#         stream.synchronize()

#         return h_output

            
def main():
    cfg = setup_cfg()
    predictor = DefaultPredictor(cfg)
    model = predictor.model
    model.eval()
    original_image = np.random.rand(512, 928, 3).astype(np.float32) #BGR
    
    aug = T.ResizeShortestEdge([cfg.INPUT.MIN_SIZE_TEST, cfg.INPUT.MIN_SIZE_TEST], cfg.INPUT.MAX_SIZE_TEST)
    
    with torch.no_grad():
        height, width = original_image.shape[:2]
        image = aug.get_transform(original_image).apply_image(original_image)
        image = torch.as_tensor(image.astype("float32").transpose(2, 0, 1)) 
        image.to(cfg.MODEL.DEVICE)

        inputs = {"image": image, "height": height, "width": width}
    
    prediction = model([inputs])[0]
    print("Predictor created: ", prediction)
    
    tensor_image = torch.from_numpy(original_image).to('cuda')
    example_inputs = {"image": tensor_image, "height": height, "width": width}
    
    torch.onnx.export(model, [example_inputs], "maskrcnn.onnx", verbose=True, input_names=["bgr_image"], output_names=["prediction"])

    
if __name__ == '__main__':
    main()