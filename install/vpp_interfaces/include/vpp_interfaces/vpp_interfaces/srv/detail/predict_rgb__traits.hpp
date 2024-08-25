// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__TRAITS_HPP_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vpp_interfaces/srv/detail/predict_rgb__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace vpp_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PredictRGB_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: image
  {
    out << "image: ";
    to_flow_style_yaml(msg.image, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PredictRGB_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: image
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "image:\n";
    to_block_style_yaml(msg.image, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PredictRGB_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vpp_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use vpp_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vpp_interfaces::srv::PredictRGB_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  vpp_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vpp_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const vpp_interfaces::srv::PredictRGB_Request & msg)
{
  return vpp_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vpp_interfaces::srv::PredictRGB_Request>()
{
  return "vpp_interfaces::srv::PredictRGB_Request";
}

template<>
inline const char * name<vpp_interfaces::srv::PredictRGB_Request>()
{
  return "vpp_interfaces/srv/PredictRGB_Request";
}

template<>
struct has_fixed_size<vpp_interfaces::srv::PredictRGB_Request>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<vpp_interfaces::srv::PredictRGB_Request>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<vpp_interfaces::srv::PredictRGB_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
#include "vpp_interfaces/msg/detail/result__traits.hpp"

namespace vpp_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PredictRGB_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PredictRGB_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PredictRGB_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace vpp_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use vpp_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vpp_interfaces::srv::PredictRGB_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  vpp_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vpp_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const vpp_interfaces::srv::PredictRGB_Response & msg)
{
  return vpp_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<vpp_interfaces::srv::PredictRGB_Response>()
{
  return "vpp_interfaces::srv::PredictRGB_Response";
}

template<>
inline const char * name<vpp_interfaces::srv::PredictRGB_Response>()
{
  return "vpp_interfaces/srv/PredictRGB_Response";
}

template<>
struct has_fixed_size<vpp_interfaces::srv::PredictRGB_Response>
  : std::integral_constant<bool, has_fixed_size<vpp_interfaces::msg::Result>::value> {};

template<>
struct has_bounded_size<vpp_interfaces::srv::PredictRGB_Response>
  : std::integral_constant<bool, has_bounded_size<vpp_interfaces::msg::Result>::value> {};

template<>
struct is_message<vpp_interfaces::srv::PredictRGB_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<vpp_interfaces::srv::PredictRGB>()
{
  return "vpp_interfaces::srv::PredictRGB";
}

template<>
inline const char * name<vpp_interfaces::srv::PredictRGB>()
{
  return "vpp_interfaces/srv/PredictRGB";
}

template<>
struct has_fixed_size<vpp_interfaces::srv::PredictRGB>
  : std::integral_constant<
    bool,
    has_fixed_size<vpp_interfaces::srv::PredictRGB_Request>::value &&
    has_fixed_size<vpp_interfaces::srv::PredictRGB_Response>::value
  >
{
};

template<>
struct has_bounded_size<vpp_interfaces::srv::PredictRGB>
  : std::integral_constant<
    bool,
    has_bounded_size<vpp_interfaces::srv::PredictRGB_Request>::value &&
    has_bounded_size<vpp_interfaces::srv::PredictRGB_Response>::value
  >
{
};

template<>
struct is_service<vpp_interfaces::srv::PredictRGB>
  : std::true_type
{
};

template<>
struct is_service_request<vpp_interfaces::srv::PredictRGB_Request>
  : std::true_type
{
};

template<>
struct is_service_response<vpp_interfaces::srv::PredictRGB_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__TRAITS_HPP_
