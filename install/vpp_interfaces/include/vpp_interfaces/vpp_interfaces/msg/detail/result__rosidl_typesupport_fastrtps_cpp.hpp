// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "vpp_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "vpp_interfaces/msg/detail/result__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace vpp_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vpp_interfaces
cdr_serialize(
  const vpp_interfaces::msg::Result & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vpp_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  vpp_interfaces::msg::Result & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vpp_interfaces
get_serialized_size(
  const vpp_interfaces::msg::Result & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vpp_interfaces
max_serialized_size_Result(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace vpp_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_vpp_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, vpp_interfaces, msg, Result)();

#ifdef __cplusplus
}
#endif

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
