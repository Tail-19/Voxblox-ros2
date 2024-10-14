// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__FUNCTIONS_H_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "vpp_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "vpp_interfaces/msg/detail/result__struct.h"

/// Initialize msg/Result message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * vpp_interfaces__msg__Result
 * )) before or use
 * vpp_interfaces__msg__Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__init(vpp_interfaces__msg__Result * msg);

/// Finalize msg/Result message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
void
vpp_interfaces__msg__Result__fini(vpp_interfaces__msg__Result * msg);

/// Create msg/Result message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * vpp_interfaces__msg__Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
vpp_interfaces__msg__Result *
vpp_interfaces__msg__Result__create();

/// Destroy msg/Result message.
/**
 * It calls
 * vpp_interfaces__msg__Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
void
vpp_interfaces__msg__Result__destroy(vpp_interfaces__msg__Result * msg);

/// Check for msg/Result message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__are_equal(const vpp_interfaces__msg__Result * lhs, const vpp_interfaces__msg__Result * rhs);

/// Copy a msg/Result message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__copy(
  const vpp_interfaces__msg__Result * input,
  vpp_interfaces__msg__Result * output);

/// Initialize array of msg/Result messages.
/**
 * It allocates the memory for the number of elements and calls
 * vpp_interfaces__msg__Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__Sequence__init(vpp_interfaces__msg__Result__Sequence * array, size_t size);

/// Finalize array of msg/Result messages.
/**
 * It calls
 * vpp_interfaces__msg__Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
void
vpp_interfaces__msg__Result__Sequence__fini(vpp_interfaces__msg__Result__Sequence * array);

/// Create array of msg/Result messages.
/**
 * It allocates the memory for the array and calls
 * vpp_interfaces__msg__Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
vpp_interfaces__msg__Result__Sequence *
vpp_interfaces__msg__Result__Sequence__create(size_t size);

/// Destroy array of msg/Result messages.
/**
 * It calls
 * vpp_interfaces__msg__Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
void
vpp_interfaces__msg__Result__Sequence__destroy(vpp_interfaces__msg__Result__Sequence * array);

/// Check for msg/Result message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__Sequence__are_equal(const vpp_interfaces__msg__Result__Sequence * lhs, const vpp_interfaces__msg__Result__Sequence * rhs);

/// Copy an array of msg/Result messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_vpp_interfaces
bool
vpp_interfaces__msg__Result__Sequence__copy(
  const vpp_interfaces__msg__Result__Sequence * input,
  vpp_interfaces__msg__Result__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__FUNCTIONS_H_
