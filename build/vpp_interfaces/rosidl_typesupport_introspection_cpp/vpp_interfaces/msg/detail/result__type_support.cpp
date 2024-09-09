// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vpp_interfaces/msg/detail/result__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vpp_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vpp_interfaces::msg::Result(_init);
}

void Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vpp_interfaces::msg::Result *>(message_memory);
  typed_message->~Result();
}

size_t size_function__Result__class_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Result__class_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void * get_function__Result__class_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__Result__class_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int64_t *>(
    get_const_function__Result__class_ids(untyped_member, index));
  auto & value = *reinterpret_cast<int64_t *>(untyped_value);
  value = item;
}

void assign_function__Result__class_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int64_t *>(
    get_function__Result__class_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const int64_t *>(untyped_value);
  item = value;
}

void resize_function__Result__class_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int64_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Result__class_names(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Result__class_names(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__Result__class_names(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__Result__class_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__Result__class_names(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__Result__class_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__Result__class_names(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__Result__class_names(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Result__scores(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Result__scores(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__Result__scores(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__Result__scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Result__scores(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Result__scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Result__scores(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__Result__scores(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Result__boxes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::RegionOfInterest> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Result__boxes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::RegionOfInterest> *>(untyped_member);
  return &member[index];
}

void * get_function__Result__boxes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::RegionOfInterest> *>(untyped_member);
  return &member[index];
}

void fetch_function__Result__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::RegionOfInterest *>(
    get_const_function__Result__boxes(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::RegionOfInterest *>(untyped_value);
  value = item;
}

void assign_function__Result__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::RegionOfInterest *>(
    get_function__Result__boxes(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::RegionOfInterest *>(untyped_value);
  item = value;
}

void resize_function__Result__boxes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::RegionOfInterest> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Result__masks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Result__masks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void * get_function__Result__masks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  return &member[index];
}

void fetch_function__Result__masks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::Image *>(
    get_const_function__Result__masks(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::Image *>(untyped_value);
  value = item;
}

void assign_function__Result__masks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::Image *>(
    get_function__Result__masks(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::Image *>(untyped_value);
  item = value;
}

void resize_function__Result__masks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::Image> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Result_message_member_array[6] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "class_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, class_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__Result__class_ids,  // size() function pointer
    get_const_function__Result__class_ids,  // get_const(index) function pointer
    get_function__Result__class_ids,  // get(index) function pointer
    fetch_function__Result__class_ids,  // fetch(index, &value) function pointer
    assign_function__Result__class_ids,  // assign(index, value) function pointer
    resize_function__Result__class_ids  // resize(index) function pointer
  },
  {
    "class_names",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, class_names),  // bytes offset in struct
    nullptr,  // default value
    size_function__Result__class_names,  // size() function pointer
    get_const_function__Result__class_names,  // get_const(index) function pointer
    get_function__Result__class_names,  // get(index) function pointer
    fetch_function__Result__class_names,  // fetch(index, &value) function pointer
    assign_function__Result__class_names,  // assign(index, value) function pointer
    resize_function__Result__class_names  // resize(index) function pointer
  },
  {
    "scores",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, scores),  // bytes offset in struct
    nullptr,  // default value
    size_function__Result__scores,  // size() function pointer
    get_const_function__Result__scores,  // get_const(index) function pointer
    get_function__Result__scores,  // get(index) function pointer
    fetch_function__Result__scores,  // fetch(index, &value) function pointer
    assign_function__Result__scores,  // assign(index, value) function pointer
    resize_function__Result__scores  // resize(index) function pointer
  },
  {
    "boxes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::RegionOfInterest>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, boxes),  // bytes offset in struct
    nullptr,  // default value
    size_function__Result__boxes,  // size() function pointer
    get_const_function__Result__boxes,  // get_const(index) function pointer
    get_function__Result__boxes,  // get(index) function pointer
    fetch_function__Result__boxes,  // fetch(index, &value) function pointer
    assign_function__Result__boxes,  // assign(index, value) function pointer
    resize_function__Result__boxes  // resize(index) function pointer
  },
  {
    "masks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces::msg::Result, masks),  // bytes offset in struct
    nullptr,  // default value
    size_function__Result__masks,  // size() function pointer
    get_const_function__Result__masks,  // get_const(index) function pointer
    get_function__Result__masks,  // get(index) function pointer
    fetch_function__Result__masks,  // fetch(index, &value) function pointer
    assign_function__Result__masks,  // assign(index, value) function pointer
    resize_function__Result__masks  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Result_message_members = {
  "vpp_interfaces::msg",  // message namespace
  "Result",  // message name
  6,  // number of fields
  sizeof(vpp_interfaces::msg::Result),
  Result_message_member_array,  // message members
  Result_init_function,  // function to initialize message memory (memory has to be allocated)
  Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Result_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vpp_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vpp_interfaces::msg::Result>()
{
  return &::vpp_interfaces::msg::rosidl_typesupport_introspection_cpp::Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vpp_interfaces, msg, Result)() {
  return &::vpp_interfaces::msg::rosidl_typesupport_introspection_cpp::Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
