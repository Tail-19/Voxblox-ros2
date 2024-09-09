// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vpp_interfaces:msg/Result.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__MSG__DETAIL__RESULT__BUILDER_HPP_
#define VPP_INTERFACES__MSG__DETAIL__RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vpp_interfaces/msg/detail/result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vpp_interfaces
{

namespace msg
{

namespace builder
{

class Init_Result_masks
{
public:
  explicit Init_Result_masks(::vpp_interfaces::msg::Result & msg)
  : msg_(msg)
  {}
  ::vpp_interfaces::msg::Result masks(::vpp_interfaces::msg::Result::_masks_type arg)
  {
    msg_.masks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

class Init_Result_boxes
{
public:
  explicit Init_Result_boxes(::vpp_interfaces::msg::Result & msg)
  : msg_(msg)
  {}
  Init_Result_masks boxes(::vpp_interfaces::msg::Result::_boxes_type arg)
  {
    msg_.boxes = std::move(arg);
    return Init_Result_masks(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

class Init_Result_scores
{
public:
  explicit Init_Result_scores(::vpp_interfaces::msg::Result & msg)
  : msg_(msg)
  {}
  Init_Result_boxes scores(::vpp_interfaces::msg::Result::_scores_type arg)
  {
    msg_.scores = std::move(arg);
    return Init_Result_boxes(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

class Init_Result_class_names
{
public:
  explicit Init_Result_class_names(::vpp_interfaces::msg::Result & msg)
  : msg_(msg)
  {}
  Init_Result_scores class_names(::vpp_interfaces::msg::Result::_class_names_type arg)
  {
    msg_.class_names = std::move(arg);
    return Init_Result_scores(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

class Init_Result_class_ids
{
public:
  explicit Init_Result_class_ids(::vpp_interfaces::msg::Result & msg)
  : msg_(msg)
  {}
  Init_Result_class_names class_ids(::vpp_interfaces::msg::Result::_class_ids_type arg)
  {
    msg_.class_ids = std::move(arg);
    return Init_Result_class_names(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

class Init_Result_header
{
public:
  Init_Result_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Result_class_ids header(::vpp_interfaces::msg::Result::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Result_class_ids(msg_);
  }

private:
  ::vpp_interfaces::msg::Result msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vpp_interfaces::msg::Result>()
{
  return vpp_interfaces::msg::builder::Init_Result_header();
}

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__MSG__DETAIL__RESULT__BUILDER_HPP_
