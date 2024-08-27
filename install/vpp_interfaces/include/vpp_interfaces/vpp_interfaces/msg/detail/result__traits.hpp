// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__TRAITS_HPP_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "vpp_interfaces/msg/detail/result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'boxes'
#include "sensor_msgs/msg/detail/region_of_interest__traits.hpp"
// Member 'masks'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace vpp_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: boxes
  {
    if (msg.boxes.size() == 0) {
      out << "boxes: []";
    } else {
      out << "boxes: [";
      size_t pending_items = msg.boxes.size();
      for (auto item : msg.boxes) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: class_ids
  {
    if (msg.class_ids.size() == 0) {
      out << "class_ids: []";
    } else {
      out << "class_ids: [";
      size_t pending_items = msg.class_ids.size();
      for (auto item : msg.class_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: class_names
  {
    if (msg.class_names.size() == 0) {
      out << "class_names: []";
    } else {
      out << "class_names: [";
      size_t pending_items = msg.class_names.size();
      for (auto item : msg.class_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: scores
  {
    if (msg.scores.size() == 0) {
      out << "scores: []";
    } else {
      out << "scores: [";
      size_t pending_items = msg.scores.size();
      for (auto item : msg.scores) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: masks
  {
    if (msg.masks.size() == 0) {
      out << "masks: []";
    } else {
      out << "masks: [";
      size_t pending_items = msg.masks.size();
      for (auto item : msg.masks) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: boxes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.boxes.size() == 0) {
      out << "boxes: []\n";
    } else {
      out << "boxes:\n";
      for (auto item : msg.boxes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: class_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.class_ids.size() == 0) {
      out << "class_ids: []\n";
    } else {
      out << "class_ids:\n";
      for (auto item : msg.class_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: class_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.class_names.size() == 0) {
      out << "class_names: []\n";
    } else {
      out << "class_names:\n";
      for (auto item : msg.class_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: scores
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.scores.size() == 0) {
      out << "scores: []\n";
    } else {
      out << "scores:\n";
      for (auto item : msg.scores) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: masks
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.masks.size() == 0) {
      out << "masks: []\n";
    } else {
      out << "masks:\n";
      for (auto item : msg.masks) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace vpp_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use vpp_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const vpp_interfaces::msg::Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  vpp_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use vpp_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const vpp_interfaces::msg::Result & msg)
{
  return vpp_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<vpp_interfaces::msg::Result>()
{
  return "vpp_interfaces::msg::Result";
}

template<>
inline const char * name<vpp_interfaces::msg::Result>()
{
  return "vpp_interfaces/msg/Result";
}

template<>
struct has_fixed_size<vpp_interfaces::msg::Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<vpp_interfaces::msg::Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<vpp_interfaces::msg::Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__TRAITS_HPP_
