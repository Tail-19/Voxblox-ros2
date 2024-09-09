// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vpp_interfaces/msg/detail/result__rosidl_typesupport_introspection_c.h"
#include "vpp_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vpp_interfaces/msg/detail/result__functions.h"
#include "vpp_interfaces/msg/detail/result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `class_ids`
// Member `scores`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `class_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `boxes`
#include "sensor_msgs/msg/region_of_interest.h"
// Member `boxes`
#include "sensor_msgs/msg/detail/region_of_interest__rosidl_typesupport_introspection_c.h"
// Member `masks`
#include "sensor_msgs/msg/image.h"
// Member `masks`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vpp_interfaces__msg__Result__init(message_memory);
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_fini_function(void * message_memory)
{
  vpp_interfaces__msg__Result__fini(message_memory);
}

size_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__class_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return member->size;
}

const void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__class_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int64_t * item =
    ((const int64_t *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_ids(untyped_member, index));
  int64_t * value =
    (int64_t *)(untyped_value);
  *value = *item;
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__class_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int64_t * item =
    ((int64_t *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_ids(untyped_member, index));
  const int64_t * value =
    (const int64_t *)(untyped_value);
  *item = *value;
}

bool vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__class_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  rosidl_runtime_c__int64__Sequence__fini(member);
  return rosidl_runtime_c__int64__Sequence__init(member, size);
}

size_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__class_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__class_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__class_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__class_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__scores(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__scores(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__scores(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__scores(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__scores(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__scores(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__scores(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__scores(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__boxes(
  const void * untyped_member)
{
  const sensor_msgs__msg__RegionOfInterest__Sequence * member =
    (const sensor_msgs__msg__RegionOfInterest__Sequence *)(untyped_member);
  return member->size;
}

const void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__boxes(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__RegionOfInterest__Sequence * member =
    (const sensor_msgs__msg__RegionOfInterest__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__boxes(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__RegionOfInterest__Sequence * member =
    (sensor_msgs__msg__RegionOfInterest__Sequence *)(untyped_member);
  return &member->data[index];
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__boxes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__RegionOfInterest * item =
    ((const sensor_msgs__msg__RegionOfInterest *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__boxes(untyped_member, index));
  sensor_msgs__msg__RegionOfInterest * value =
    (sensor_msgs__msg__RegionOfInterest *)(untyped_value);
  *value = *item;
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__boxes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__RegionOfInterest * item =
    ((sensor_msgs__msg__RegionOfInterest *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__boxes(untyped_member, index));
  const sensor_msgs__msg__RegionOfInterest * value =
    (const sensor_msgs__msg__RegionOfInterest *)(untyped_value);
  *item = *value;
}

bool vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__boxes(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__RegionOfInterest__Sequence * member =
    (sensor_msgs__msg__RegionOfInterest__Sequence *)(untyped_member);
  sensor_msgs__msg__RegionOfInterest__Sequence__fini(member);
  return sensor_msgs__msg__RegionOfInterest__Sequence__init(member, size);
}

size_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__masks(
  const void * untyped_member)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return member->size;
}

const void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__masks(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image__Sequence * member =
    (const sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__masks(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  return &member->data[index];
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__masks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__Image * item =
    ((const sensor_msgs__msg__Image *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__masks(untyped_member, index));
  sensor_msgs__msg__Image * value =
    (sensor_msgs__msg__Image *)(untyped_value);
  *value = *item;
}

void vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__masks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__Image * item =
    ((sensor_msgs__msg__Image *)
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__masks(untyped_member, index));
  const sensor_msgs__msg__Image * value =
    (const sensor_msgs__msg__Image *)(untyped_value);
  *item = *value;
}

bool vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__masks(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__Image__Sequence * member =
    (sensor_msgs__msg__Image__Sequence *)(untyped_member);
  sensor_msgs__msg__Image__Sequence__fini(member);
  return sensor_msgs__msg__Image__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "class_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, class_ids),  // bytes offset in struct
    NULL,  // default value
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__class_ids,  // size() function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_ids,  // get_const(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_ids,  // get(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__class_ids,  // fetch(index, &value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__class_ids,  // assign(index, value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__class_ids  // resize(index) function pointer
  },
  {
    "class_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, class_names),  // bytes offset in struct
    NULL,  // default value
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__class_names,  // size() function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__class_names,  // get_const(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__class_names,  // get(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__class_names,  // fetch(index, &value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__class_names,  // assign(index, value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__class_names  // resize(index) function pointer
  },
  {
    "scores",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, scores),  // bytes offset in struct
    NULL,  // default value
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__scores,  // size() function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__scores,  // get_const(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__scores,  // get(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__scores,  // fetch(index, &value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__scores,  // assign(index, value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__scores  // resize(index) function pointer
  },
  {
    "boxes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, boxes),  // bytes offset in struct
    NULL,  // default value
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__boxes,  // size() function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__boxes,  // get_const(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__boxes,  // get(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__boxes,  // fetch(index, &value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__boxes,  // assign(index, value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__boxes  // resize(index) function pointer
  },
  {
    "masks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__msg__Result, masks),  // bytes offset in struct
    NULL,  // default value
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__size_function__Result__masks,  // size() function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_const_function__Result__masks,  // get_const(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__get_function__Result__masks,  // get(index) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__fetch_function__Result__masks,  // fetch(index, &value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__assign_function__Result__masks,  // assign(index, value) function pointer
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__resize_function__Result__masks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_members = {
  "vpp_interfaces__msg",  // message namespace
  "Result",  // message name
  6,  // number of fields
  sizeof(vpp_interfaces__msg__Result),
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_member_array,  // message members
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_init_function,  // function to initialize message memory (memory has to be allocated)
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_type_support_handle = {
  0,
  &vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vpp_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, msg, Result)() {
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, RegionOfInterest)();
  vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_type_support_handle.typesupport_identifier) {
    vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vpp_interfaces__msg__Result__rosidl_typesupport_introspection_c__Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
