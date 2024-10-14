// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_HPP_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'boxes'
#include "sensor_msgs/msg/detail/region_of_interest__struct.hpp"
// Member 'masks'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vpp_interfaces__msg__Result __attribute__((deprecated))
#else
# define DEPRECATED__vpp_interfaces__msg__Result __declspec(deprecated)
#endif

namespace vpp_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Result_
{
  using Type = Result_<ContainerAllocator>;

  explicit Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _class_ids_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _class_ids_type class_ids;
  using _class_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _class_names_type class_names;
  using _scores_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _scores_type scores;
  using _boxes_type =
    std::vector<sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>>>;
  _boxes_type boxes;
  using _masks_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>>;
  _masks_type masks;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__class_ids(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->class_ids = _arg;
    return *this;
  }
  Type & set__class_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->class_names = _arg;
    return *this;
  }
  Type & set__scores(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->scores = _arg;
    return *this;
  }
  Type & set__boxes(
    const std::vector<sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::RegionOfInterest_<ContainerAllocator>>> & _arg)
  {
    this->boxes = _arg;
    return *this;
  }
  Type & set__masks(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<sensor_msgs::msg::Image_<ContainerAllocator>>> & _arg)
  {
    this->masks = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vpp_interfaces::msg::Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const vpp_interfaces::msg::Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vpp_interfaces::msg::Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vpp_interfaces::msg::Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::msg::Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::msg::Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vpp_interfaces::msg::Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vpp_interfaces::msg::Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vpp_interfaces::msg::Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vpp_interfaces::msg::Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vpp_interfaces__msg__Result
    std::shared_ptr<vpp_interfaces::msg::Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vpp_interfaces__msg__Result
    std::shared_ptr<vpp_interfaces::msg::Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Result_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->class_ids != other.class_ids) {
      return false;
    }
    if (this->class_names != other.class_names) {
      return false;
    }
    if (this->scores != other.scores) {
      return false;
    }
    if (this->boxes != other.boxes) {
      return false;
    }
    if (this->masks != other.masks) {
      return false;
    }
    return true;
  }
  bool operator!=(const Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Result_

// alias to use template instance with default allocator
using Result =
  vpp_interfaces::msg::Result_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_HPP_
