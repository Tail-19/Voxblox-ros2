cmake_minimum_required(VERSION 3.8)
project(depth_segmentation_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW)
endif()

set(PCL_ROOT "/usr/include/pcl-1.12")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


link_directories(
  ${CMAKE_SOURCE_DIR}/lib
)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(OpenCV REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(pcl_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io visualization)
find_package(Eigen3 REQUIRED)
find_package (glog 0.8.0 EXACT REQUIRED)
find_package(gflags REQUIRED)
find_package(vpp_interfaces REQUIRED)

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${glog_INCLUDE_DIRS}
)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
  message(STATUS "OpenMP support found, enabling OpenMP flags.")
  set(OpenMP_FLAGS ${OpenMP_CXX_FLAGS})
  set(OpenMP_LIBS OpenMP::OpenMP_CXX)
else()
  message(STATUS "OpenMP support not found, building without OpenMP support.")
  set(OpenMP_FLAGS "")
  set(OpenMP_LIBS "")
endif()


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


add_library(${PROJECT_NAME} SHARED
  src/depth_segmentation_ros2.cpp
)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenMP_LIBS}  ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} PUBLIC glog::glog)
target_compile_options(${PROJECT_NAME} PRIVATE ${OpenMP_FLAGS})
# ament_target_dependencies(${PROJECT_NAME})


add_executable(${PROJECT_NAME}_node
  src/depth_segmentation_ros2_node.cpp
)
ament_target_dependencies(${PROJECT_NAME}_node
  rclcpp
  std_msgs
  sensor_msgs
  geometry_msgs
  cv_bridge
  image_transport
  tf2
  tf2_ros
  tf2_eigen
  pcl_ros
  Eigen3
  PCL
  vpp_interfaces
)
target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME})


# Test
# find_package(ament_cmake_gtest REQUIRED)
# ament_add_gtest(test_depth_segmentation PRIVATE test/test_depth_segmentation.cpp)
# if(TARGET test_depth_segmentation)
#   target_link_libraries(test_depth_segmentation ${PROJECT_NAME} pthread)
# endif()
install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}   # <-- documentation prepends export_
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(
  DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch/
)

install(
  DIRECTORY cfg/
  DESTINATION share/${PROJECT_NAME}/cfg/
)

install(TARGETS ${PROJECT_NAME}_node
    DESTINATION lib/${PROJECT_NAME})

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_package()
