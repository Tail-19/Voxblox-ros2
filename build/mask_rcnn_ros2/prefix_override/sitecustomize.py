import sys
if sys.prefix == '/home/alpha/anaconda3/envs/voxblox':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/alpha/Research/voxblox/install/mask_rcnn_ros2'
