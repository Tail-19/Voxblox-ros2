#ROS
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from vpp_interfaces.srv import PredictRGB

#OpenCV
from cv_bridge import CvBridge
import cv2

#ZED
import pyzed.sl as sl

#This class supports publish and request for ZED camera
class CameraZed(Node):

    def __init__(self):
        super().__init__('camera_zed')
        self._publisher = self.create_publisher(Image, 'image_raw', 10)
        #Camera
        self.zed = sl.Camera()
        init_params = sl.InitParameters()
        init_params.camera_resolution = sl.RESOLUTION.AUTO # Use HD720 opr HD1200 video mode, depending on camera type.
        init_params.camera_fps = 30  # Set fps at 30
        err = self.zed.open(init_params)
        if err != sl.ERROR_CODE.SUCCESS:
            print("Camera Open : "+repr(err)+". Exit program.")
            exit()

        self.bridge = CvBridge()
        
        self.timer = self.create_timer(1/init_params.camera_fps, self.timer_callback)

    def timer_callback(self):
        image = sl.Mat()
        runtime_parameters = sl.RuntimeParameters()

        if self.zed.grab(runtime_parameters) == sl.ERROR_CODE.SUCCESS:
            self.zed.retrieve_image(image, sl.VIEW.LEFT)  # Retrieve the left image the format is bgra
            image = image.get_data() #get the numpy tensor
            image_msg = self.bridge.cv2_to_imgmsg(image, "bgra8") #convert numpy tensor to image message, bgra8 is the encoding type

            self._publisher.publish(image_msg)
            self.get_logger().info("Publishing ZED image frame, wait for image processing...")
        
def main(args=None):
    rclpy.init(args=args)

    camera_zed = CameraZed()

    rclpy.spin(camera_zed)

    camera_zed.destroy_node()
    rclpy.shutdown()

if __name__== '__main__':
    main()