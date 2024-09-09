// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice
#include "vpp_interfaces/msg/detail/result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `class_ids`
// Member `scores`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `class_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `boxes`
#include "sensor_msgs/msg/detail/region_of_interest__functions.h"
// Member `masks`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
vpp_interfaces__msg__Result__init(vpp_interfaces__msg__Result * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  // class_ids
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->class_ids, 0)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  // class_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->class_names, 0)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  // scores
  if (!rosidl_runtime_c__float__Sequence__init(&msg->scores, 0)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  // boxes
  if (!sensor_msgs__msg__RegionOfInterest__Sequence__init(&msg->boxes, 0)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  // masks
  if (!sensor_msgs__msg__Image__Sequence__init(&msg->masks, 0)) {
    vpp_interfaces__msg__Result__fini(msg);
    return false;
  }
  return true;
}

void
vpp_interfaces__msg__Result__fini(vpp_interfaces__msg__Result * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // class_ids
  rosidl_runtime_c__int64__Sequence__fini(&msg->class_ids);
  // class_names
  rosidl_runtime_c__String__Sequence__fini(&msg->class_names);
  // scores
  rosidl_runtime_c__float__Sequence__fini(&msg->scores);
  // boxes
  sensor_msgs__msg__RegionOfInterest__Sequence__fini(&msg->boxes);
  // masks
  sensor_msgs__msg__Image__Sequence__fini(&msg->masks);
}

bool
vpp_interfaces__msg__Result__are_equal(const vpp_interfaces__msg__Result * lhs, const vpp_interfaces__msg__Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // class_ids
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->class_ids), &(rhs->class_ids)))
  {
    return false;
  }
  // class_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->class_names), &(rhs->class_names)))
  {
    return false;
  }
  // scores
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->scores), &(rhs->scores)))
  {
    return false;
  }
  // boxes
  if (!sensor_msgs__msg__RegionOfInterest__Sequence__are_equal(
      &(lhs->boxes), &(rhs->boxes)))
  {
    return false;
  }
  // masks
  if (!sensor_msgs__msg__Image__Sequence__are_equal(
      &(lhs->masks), &(rhs->masks)))
  {
    return false;
  }
  return true;
}

bool
vpp_interfaces__msg__Result__copy(
  const vpp_interfaces__msg__Result * input,
  vpp_interfaces__msg__Result * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // class_ids
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->class_ids), &(output->class_ids)))
  {
    return false;
  }
  // class_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->class_names), &(output->class_names)))
  {
    return false;
  }
  // scores
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->scores), &(output->scores)))
  {
    return false;
  }
  // boxes
  if (!sensor_msgs__msg__RegionOfInterest__Sequence__copy(
      &(input->boxes), &(output->boxes)))
  {
    return false;
  }
  // masks
  if (!sensor_msgs__msg__Image__Sequence__copy(
      &(input->masks), &(output->masks)))
  {
    return false;
  }
  return true;
}

vpp_interfaces__msg__Result *
vpp_interfaces__msg__Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__msg__Result * msg = (vpp_interfaces__msg__Result *)allocator.allocate(sizeof(vpp_interfaces__msg__Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vpp_interfaces__msg__Result));
  bool success = vpp_interfaces__msg__Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vpp_interfaces__msg__Result__destroy(vpp_interfaces__msg__Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vpp_interfaces__msg__Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vpp_interfaces__msg__Result__Sequence__init(vpp_interfaces__msg__Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__msg__Result * data = NULL;

  if (size) {
    data = (vpp_interfaces__msg__Result *)allocator.zero_allocate(size, sizeof(vpp_interfaces__msg__Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vpp_interfaces__msg__Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vpp_interfaces__msg__Result__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
vpp_interfaces__msg__Result__Sequence__fini(vpp_interfaces__msg__Result__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      vpp_interfaces__msg__Result__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

vpp_interfaces__msg__Result__Sequence *
vpp_interfaces__msg__Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__msg__Result__Sequence * array = (vpp_interfaces__msg__Result__Sequence *)allocator.allocate(sizeof(vpp_interfaces__msg__Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vpp_interfaces__msg__Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vpp_interfaces__msg__Result__Sequence__destroy(vpp_interfaces__msg__Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vpp_interfaces__msg__Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vpp_interfaces__msg__Result__Sequence__are_equal(const vpp_interfaces__msg__Result__Sequence * lhs, const vpp_interfaces__msg__Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vpp_interfaces__msg__Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vpp_interfaces__msg__Result__Sequence__copy(
  const vpp_interfaces__msg__Result__Sequence * input,
  vpp_interfaces__msg__Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vpp_interfaces__msg__Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vpp_interfaces__msg__Result * data =
      (vpp_interfaces__msg__Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vpp_interfaces__msg__Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vpp_interfaces__msg__Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vpp_interfaces__msg__Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
