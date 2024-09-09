std_msgs/Header header

# Integer class IDs for each bounding box
int64[] class_ids

# String class IDs for each bouding box
string[] class_names

# Float probability scores of the class_id
float32[] scores 

# Bounding boxes in pixels
sensor_msgs/RegionOfInterest[] boxes

# Instance masks as Image
sensor_msgs/Image[] masks


