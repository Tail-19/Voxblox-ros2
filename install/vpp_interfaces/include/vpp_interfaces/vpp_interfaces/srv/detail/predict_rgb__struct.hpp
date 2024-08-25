// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_HPP_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__vpp_interfaces__srv__PredictRGB_Request __attribute__((deprecated))
#else
# define DEPRECATED__vpp_interfaces__srv__PredictRGB_Request __declspec(deprecated)
#endif

namespace vpp_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PredictRGB_Request_
{
  using Type = PredictRGB_Request_<ContainerAllocator>;

  explicit PredictRGB_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    (void)_init;
  }

  explicit PredictRGB_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vpp_interfaces__srv__PredictRGB_Request
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vpp_interfaces__srv__PredictRGB_Request
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PredictRGB_Request_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const PredictRGB_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PredictRGB_Request_

// alias to use template instance with default allocator
using PredictRGB_Request =
  vpp_interfaces::srv::PredictRGB_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vpp_interfaces


// Include directives for member types
// Member 'result'
#include "vpp_interfaces/msg/detail/result__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vpp_interfaces__srv__PredictRGB_Response __attribute__((deprecated))
#else
# define DEPRECATED__vpp_interfaces__srv__PredictRGB_Response __declspec(deprecated)
#endif

namespace vpp_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PredictRGB_Response_
{
  using Type = PredictRGB_Response_<ContainerAllocator>;

  explicit PredictRGB_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    (void)_init;
  }

  explicit PredictRGB_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _result_type =
    vpp_interfaces::msg::Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const vpp_interfaces::msg::Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vpp_interfaces__srv__PredictRGB_Response
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vpp_interfaces__srv__PredictRGB_Response
    std::shared_ptr<vpp_interfaces::srv::PredictRGB_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PredictRGB_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PredictRGB_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PredictRGB_Response_

// alias to use template instance with default allocator
using PredictRGB_Response =
  vpp_interfaces::srv::PredictRGB_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace vpp_interfaces

namespace vpp_interfaces
{

namespace srv
{

struct PredictRGB
{
  using Request = vpp_interfaces::srv::PredictRGB_Request;
  using Response = vpp_interfaces::srv::PredictRGB_Response;
};

}  // namespace srv

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_HPP_
