// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vpp_interfaces:srv/PredictRGB.idl
// generated code does not contain a copyright notice

#ifndef VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__BUILDER_HPP_
#define VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vpp_interfaces/srv/detail/predict_rgb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vpp_interfaces
{

namespace srv
{

namespace builder
{

class Init_PredictRGB_Request_image
{
public:
  Init_PredictRGB_Request_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vpp_interfaces::srv::PredictRGB_Request image(::vpp_interfaces::srv::PredictRGB_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vpp_interfaces::srv::PredictRGB_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vpp_interfaces::srv::PredictRGB_Request>()
{
  return vpp_interfaces::srv::builder::Init_PredictRGB_Request_image();
}

}  // namespace vpp_interfaces


namespace vpp_interfaces
{

namespace srv
{

namespace builder
{

class Init_PredictRGB_Response_result
{
public:
  Init_PredictRGB_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::vpp_interfaces::srv::PredictRGB_Response result(::vpp_interfaces::srv::PredictRGB_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vpp_interfaces::srv::PredictRGB_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vpp_interfaces::srv::PredictRGB_Response>()
{
  return vpp_interfaces::srv::builder::Init_PredictRGB_Response_result();
}

}  // namespace vpp_interfaces

#endif  // VPP_INTERFACES__SRV__DETAIL__PREDICT_RGB__BUILDER_HPP_
