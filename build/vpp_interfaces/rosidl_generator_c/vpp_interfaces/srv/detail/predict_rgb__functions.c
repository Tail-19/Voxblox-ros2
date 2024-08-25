// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice
#include "vpp_interfaces/srv/detail/predict_rgb__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
vpp_interfaces__srv__PredictRGB_Request__init(vpp_interfaces__srv__PredictRGB_Request * msg)
{
  if (!msg) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__init(&msg->image)) {
    vpp_interfaces__srv__PredictRGB_Request__fini(msg);
    return false;
  }
  return true;
}

void
vpp_interfaces__srv__PredictRGB_Request__fini(vpp_interfaces__srv__PredictRGB_Request * msg)
{
  if (!msg) {
    return;
  }
  // image
  sensor_msgs__msg__Image__fini(&msg->image);
}

bool
vpp_interfaces__srv__PredictRGB_Request__are_equal(const vpp_interfaces__srv__PredictRGB_Request * lhs, const vpp_interfaces__srv__PredictRGB_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__are_equal(
      &(lhs->image), &(rhs->image)))
  {
    return false;
  }
  return true;
}

bool
vpp_interfaces__srv__PredictRGB_Request__copy(
  const vpp_interfaces__srv__PredictRGB_Request * input,
  vpp_interfaces__srv__PredictRGB_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // image
  if (!sensor_msgs__msg__Image__copy(
      &(input->image), &(output->image)))
  {
    return false;
  }
  return true;
}

vpp_interfaces__srv__PredictRGB_Request *
vpp_interfaces__srv__PredictRGB_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Request * msg = (vpp_interfaces__srv__PredictRGB_Request *)allocator.allocate(sizeof(vpp_interfaces__srv__PredictRGB_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vpp_interfaces__srv__PredictRGB_Request));
  bool success = vpp_interfaces__srv__PredictRGB_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vpp_interfaces__srv__PredictRGB_Request__destroy(vpp_interfaces__srv__PredictRGB_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vpp_interfaces__srv__PredictRGB_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vpp_interfaces__srv__PredictRGB_Request__Sequence__init(vpp_interfaces__srv__PredictRGB_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Request * data = NULL;

  if (size) {
    data = (vpp_interfaces__srv__PredictRGB_Request *)allocator.zero_allocate(size, sizeof(vpp_interfaces__srv__PredictRGB_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vpp_interfaces__srv__PredictRGB_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vpp_interfaces__srv__PredictRGB_Request__fini(&data[i - 1]);
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
vpp_interfaces__srv__PredictRGB_Request__Sequence__fini(vpp_interfaces__srv__PredictRGB_Request__Sequence * array)
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
      vpp_interfaces__srv__PredictRGB_Request__fini(&array->data[i]);
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

vpp_interfaces__srv__PredictRGB_Request__Sequence *
vpp_interfaces__srv__PredictRGB_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Request__Sequence * array = (vpp_interfaces__srv__PredictRGB_Request__Sequence *)allocator.allocate(sizeof(vpp_interfaces__srv__PredictRGB_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vpp_interfaces__srv__PredictRGB_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vpp_interfaces__srv__PredictRGB_Request__Sequence__destroy(vpp_interfaces__srv__PredictRGB_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vpp_interfaces__srv__PredictRGB_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vpp_interfaces__srv__PredictRGB_Request__Sequence__are_equal(const vpp_interfaces__srv__PredictRGB_Request__Sequence * lhs, const vpp_interfaces__srv__PredictRGB_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vpp_interfaces__srv__PredictRGB_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vpp_interfaces__srv__PredictRGB_Request__Sequence__copy(
  const vpp_interfaces__srv__PredictRGB_Request__Sequence * input,
  vpp_interfaces__srv__PredictRGB_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vpp_interfaces__srv__PredictRGB_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vpp_interfaces__srv__PredictRGB_Request * data =
      (vpp_interfaces__srv__PredictRGB_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vpp_interfaces__srv__PredictRGB_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vpp_interfaces__srv__PredictRGB_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vpp_interfaces__srv__PredictRGB_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "vpp_interfaces/msg/detail/result__functions.h"

bool
vpp_interfaces__srv__PredictRGB_Response__init(vpp_interfaces__srv__PredictRGB_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!vpp_interfaces__msg__Result__init(&msg->result)) {
    vpp_interfaces__srv__PredictRGB_Response__fini(msg);
    return false;
  }
  return true;
}

void
vpp_interfaces__srv__PredictRGB_Response__fini(vpp_interfaces__srv__PredictRGB_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  vpp_interfaces__msg__Result__fini(&msg->result);
}

bool
vpp_interfaces__srv__PredictRGB_Response__are_equal(const vpp_interfaces__srv__PredictRGB_Response * lhs, const vpp_interfaces__srv__PredictRGB_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!vpp_interfaces__msg__Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
vpp_interfaces__srv__PredictRGB_Response__copy(
  const vpp_interfaces__srv__PredictRGB_Response * input,
  vpp_interfaces__srv__PredictRGB_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!vpp_interfaces__msg__Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

vpp_interfaces__srv__PredictRGB_Response *
vpp_interfaces__srv__PredictRGB_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Response * msg = (vpp_interfaces__srv__PredictRGB_Response *)allocator.allocate(sizeof(vpp_interfaces__srv__PredictRGB_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(vpp_interfaces__srv__PredictRGB_Response));
  bool success = vpp_interfaces__srv__PredictRGB_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
vpp_interfaces__srv__PredictRGB_Response__destroy(vpp_interfaces__srv__PredictRGB_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    vpp_interfaces__srv__PredictRGB_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
vpp_interfaces__srv__PredictRGB_Response__Sequence__init(vpp_interfaces__srv__PredictRGB_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Response * data = NULL;

  if (size) {
    data = (vpp_interfaces__srv__PredictRGB_Response *)allocator.zero_allocate(size, sizeof(vpp_interfaces__srv__PredictRGB_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = vpp_interfaces__srv__PredictRGB_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        vpp_interfaces__srv__PredictRGB_Response__fini(&data[i - 1]);
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
vpp_interfaces__srv__PredictRGB_Response__Sequence__fini(vpp_interfaces__srv__PredictRGB_Response__Sequence * array)
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
      vpp_interfaces__srv__PredictRGB_Response__fini(&array->data[i]);
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

vpp_interfaces__srv__PredictRGB_Response__Sequence *
vpp_interfaces__srv__PredictRGB_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  vpp_interfaces__srv__PredictRGB_Response__Sequence * array = (vpp_interfaces__srv__PredictRGB_Response__Sequence *)allocator.allocate(sizeof(vpp_interfaces__srv__PredictRGB_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = vpp_interfaces__srv__PredictRGB_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
vpp_interfaces__srv__PredictRGB_Response__Sequence__destroy(vpp_interfaces__srv__PredictRGB_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    vpp_interfaces__srv__PredictRGB_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
vpp_interfaces__srv__PredictRGB_Response__Sequence__are_equal(const vpp_interfaces__srv__PredictRGB_Response__Sequence * lhs, const vpp_interfaces__srv__PredictRGB_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!vpp_interfaces__srv__PredictRGB_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
vpp_interfaces__srv__PredictRGB_Response__Sequence__copy(
  const vpp_interfaces__srv__PredictRGB_Response__Sequence * input,
  vpp_interfaces__srv__PredictRGB_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(vpp_interfaces__srv__PredictRGB_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    vpp_interfaces__srv__PredictRGB_Response * data =
      (vpp_interfaces__srv__PredictRGB_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!vpp_interfaces__srv__PredictRGB_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          vpp_interfaces__srv__PredictRGB_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!vpp_interfaces__srv__PredictRGB_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
