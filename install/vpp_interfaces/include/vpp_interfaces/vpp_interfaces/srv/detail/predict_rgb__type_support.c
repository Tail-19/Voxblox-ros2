// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vpp_interfaces/srv/detail/predict_rgb__rosidl_typesupport_introspection_c.h"
#include "vpp_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vpp_interfaces/srv/detail/predict_rgb__functions.h"
#include "vpp_interfaces/srv/detail/predict_rgb__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vpp_interfaces__srv__PredictRGB_Request__init(message_memory);
}

void vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_fini_function(void * message_memory)
{
  vpp_interfaces__srv__PredictRGB_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_member_array[1] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__srv__PredictRGB_Request, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_members = {
  "vpp_interfaces__srv",  // message namespace
  "PredictRGB_Request",  // message name
  1,  // number of fields
  sizeof(vpp_interfaces__srv__PredictRGB_Request),
  vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_member_array,  // message members
  vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_type_support_handle = {
  0,
  &vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vpp_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Request)() {
  vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_type_support_handle.typesupport_identifier) {
    vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vpp_interfaces__srv__PredictRGB_Request__rosidl_typesupport_introspection_c__PredictRGB_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "vpp_interfaces/srv/detail/predict_rgb__rosidl_typesupport_introspection_c.h"
// already included above
// #include "vpp_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "vpp_interfaces/srv/detail/predict_rgb__functions.h"
// already included above
// #include "vpp_interfaces/srv/detail/predict_rgb__struct.h"


// Include directives for member types
// Member `result`
#include "vpp_interfaces/msg/result.h"
// Member `result`
#include "vpp_interfaces/msg/detail/result__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vpp_interfaces__srv__PredictRGB_Response__init(message_memory);
}

void vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_fini_function(void * message_memory)
{
  vpp_interfaces__srv__PredictRGB_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vpp_interfaces__srv__PredictRGB_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_members = {
  "vpp_interfaces__srv",  // message namespace
  "PredictRGB_Response",  // message name
  1,  // number of fields
  sizeof(vpp_interfaces__srv__PredictRGB_Response),
  vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_member_array,  // message members
  vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_type_support_handle = {
  0,
  &vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vpp_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Response)() {
  vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, msg, Result)();
  if (!vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_type_support_handle.typesupport_identifier) {
    vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vpp_interfaces__srv__PredictRGB_Response__rosidl_typesupport_introspection_c__PredictRGB_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "vpp_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "vpp_interfaces/srv/detail/predict_rgb__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_members = {
  "vpp_interfaces__srv",  // service namespace
  "PredictRGB",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_Request_message_type_support_handle,
  NULL  // response message
  // vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_Response_message_type_support_handle
};

static rosidl_service_type_support_t vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_type_support_handle = {
  0,
  &vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vpp_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB)() {
  if (!vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_type_support_handle.typesupport_identifier) {
    vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vpp_interfaces, srv, PredictRGB_Response)()->data;
  }

  return &vpp_interfaces__srv__detail__predict_rgb__rosidl_typesupport_introspection_c__PredictRGB_service_type_support_handle;
}
