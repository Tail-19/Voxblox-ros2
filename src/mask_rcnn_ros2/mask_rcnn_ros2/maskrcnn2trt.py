import torch 
from torchvision.models.detection import mask_rcnn
import torch_tensorrt
import torch._dynamo
import time
torch._dynamo.config.suppress_errors = True


model = mask_rcnn.maskrcnn_resnet50_fpn(pretrained=True).eval().cuda()
input_shape = (3, 512, 928)
x = torch.randn(1, *input_shape).cuda()

# model_trt = torch.compile(model,
#                         backend="tensorrt",
#                         dynamic=False,
#                         options={"truncate_long_and_double": True,
#                                 "enabled_precisions": {torch.half}})

# print("===Model compiled to TensorRT===")
# y_trt = model_trt(x)
# print("===Model first time run===")

start = time.time()
y = model(x)
print("PyTorch time: ", time.time() - start)
print("The model output: \n", y)

# start = time.time()
# y_trt = model_trt(x)
# print("TensorRT time: ", time.time() - start)
# print("The model_trt output: \n", y_trt)


