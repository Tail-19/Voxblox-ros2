// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_H_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

/// Struct defined in srv/PredictRGB in the package vpp_interfaces.
typedef struct vpp_interfaces__srv__PredictRGB_Request
{
  sensor_msgs__msg__Image image;
} vpp_interfaces__srv__PredictRGB_Request;

// Struct for a sequence of vpp_interfaces__srv__PredictRGB_Request.
typedef struct vpp_interfaces__srv__PredictRGB_Request__Sequence
{
  vpp_interfaces__srv__PredictRGB_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vpp_interfaces__srv__PredictRGB_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "vpp_interfaces/msg/detail/result__struct.h"

/// Struct defined in srv/PredictRGB in the package vpp_interfaces.
typedef struct vpp_interfaces__srv__PredictRGB_Response
{
  vpp_interfaces__msg__Result result;
} vpp_interfaces__srv__PredictRGB_Response;

// Struct for a sequence of vpp_interfaces__srv__PredictRGB_Response.
typedef struct vpp_interfaces__srv__PredictRGB_Response__Sequence
{
  vpp_interfaces__srv__PredictRGB_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} vpp_interfaces__srv__PredictRGB_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__STRUCT_H_
