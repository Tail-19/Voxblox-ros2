// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vpp_interfaces:srv/PredictDepth.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__BUILDER_HPP_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vpp_interfaces/srv/detail/predict_depth__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vpp_interfaces
{

namespace srv
{

namespace builder
{

class Init_PredictDepth_Request_result
{
public:
  explicit Init_PredictDepth_Request_result(::vpp_interfaces::srv::PredictDepth_Request & msg)
  : msg_(msg)
  {}
  ::vpp_interfaces::srv::PredictDepth_Request result(::vpp_interfaces::srv::PredictDepth_Request::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vpp_interfaces::srv::PredictDepth_Request msg_;
};

class Init_PredictDepth_Request_image
{
public:
  Init_PredictDepth_Request_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PredictDepth_Request_result image(::vpp_interfaces::srv::PredictDepth_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return Init_PredictDepth_Request_result(msg_);
  }

private:
  ::vpp_interfaces::srv::PredictDepth_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vpp_interfaces::srv::PredictDepth_Request>()
{
  return vpp_interfaces::srv::builder::Init_PredictDepth_Request_image();
}

}  // namespace vpp_interfaces


namespace vpp_interfaces
{

namespace srv
{

namespace builder
{

class Init_PredictDepth_Response_object_segment
{
public:
  Init_PredictDepth_Response_object_segment()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vpp_interfaces::srv::PredictDepth_Response object_segment(::vpp_interfaces::srv::PredictDepth_Response::_object_segment_type arg)
  {
    msg_.object_segment = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vpp_interfaces::srv::PredictDepth_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vpp_interfaces::srv::PredictDepth_Response>()
{
  return vpp_interfaces::srv::builder::Init_PredictDepth_Response_object_segment();
}

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_DEPTH__BUILDER_HPP_
