// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vpp_interfaces:srv/PredictDepth.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__STRUCT_HPP_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"
// Member 'result'
#include "vpp_interfaces/msg/detail/result__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vpp_interfaces__srv__PredictDepth_Request __attribute__((deprecated))
#else
# define DEPRECATED__vpp_interfaces__srv__PredictDepth_Request __declspec(deprecated)
#endif

namespace vpp_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PredictDepth_Request_
{
  using Type = PredictDepth_Request_<ContainerAllocator>;

  explicit PredictDepth_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init),
    result(_init)
  {
    (void)_init;
  }

  explicit PredictDepth_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init),
    result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;
  using _result_type =
    vpp_interfaces::msg::Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }
  Type & set__result(
    const vpp_interfaces::msg::Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vpp_interfaces__srv__PredictDepth_Request
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vpp_interfaces__srv__PredictDepth_Request
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PredictDepth_Request_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PredictDepth_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PredictDepth_Request_

// alias to use template instance with default allocator
using PredictDepth_Request =
  vpp_interfaces::srv::PredictDepth_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vpp_interfaces


// Include directives for member types
// Member 'object_segment'
#include "sensor_msgs/msg/detail/point_cloud2__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vpp_interfaces__srv__PredictDepth_Response __attribute__((deprecated))
#else
# define DEPRECATED__vpp_interfaces__srv__PredictDepth_Response __declspec(deprecated)
#endif

namespace vpp_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PredictDepth_Response_
{
  using Type = PredictDepth_Response_<ContainerAllocator>;

  explicit PredictDepth_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_segment(_init)
  {
    (void)_init;
  }

  explicit PredictDepth_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_segment(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _object_segment_type =
    sensor_msgs::msg::PointCloud2_<ContainerAllocator>;
  _object_segment_type object_segment;

  // setters for named parameter idiom
  Type & set__object_segment(
    const sensor_msgs::msg::PointCloud2_<ContainerAllocator> & _arg)
  {
    this->object_segment = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vpp_interfaces__srv__PredictDepth_Response
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vpp_interfaces__srv__PredictDepth_Response
    std::shared_ptr<vpp_interfaces::srv::PredictDepth_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PredictDepth_Response_ & other) const
  {
    if (this->object_segment != other.object_segment) {
      return false;
    }
    return true;
  }
  bool operator!=(const PredictDepth_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PredictDepth_Response_

// alias to use template instance with default allocator
using PredictDepth_Response =
  vpp_interfaces::srv::PredictDepth_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vpp_interfaces

namespace vpp_interfaces
{

namespace srv
{

struct PredictDepth
{
  using Request = vpp_interfaces::srv::PredictDepth_Request;
  using Response = vpp_interfaces::srv::PredictDepth_Response;
};

}  // namespace srv

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__STRUCT_HPP_
