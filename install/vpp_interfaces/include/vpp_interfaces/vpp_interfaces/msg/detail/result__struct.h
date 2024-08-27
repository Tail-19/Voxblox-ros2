// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_H_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'boxes'
#include "sensor_msgs/msg/detail/region_of_interest__struct.h"
// Member 'class_ids'
// Member 'scores'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'class_names'
#include "rosidl_runtime_c/string.h"
// Member 'masks'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in msg/Result in the package vpp_interfaces.
typedef struct vpp_interfaces__msg__Result
{
  std_msgs__msg__Header header;
  /// Bounding boxes in pixels
  sensor_msgs__msg__RegionOfInterest__Sequence boxes;
  /// Integer class IDs for each bounding box
  rosidl_runtime_c__int64__Sequence class_ids;
  /// String class IDs for each bouding box
  rosidl_runtime_c__String__Sequence class_names;
  /// Float probability scores of the class_id
  rosidl_runtime_c__float__Sequence scores;
  /// Instance masks as Image
  sensor_msgs__msg__Image__Sequence masks;
} vpp_interfaces__msg__Result;

// Struct for a sequence of vpp_interfaces__msg__Result.
typedef struct vpp_interfaces__msg__Result__Sequence
{
  vpp_interfaces__msg__Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vpp_interfaces__msg__Result__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__STRUCT_H_
