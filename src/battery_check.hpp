#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include "sensor_msgs/msg/battery_state.hpp"

using namespace BT;

class BatteryCheck: public RosTopicSubNode<sensor_msgs::msg::BatteryState>
{
public:

  BatteryCheck(const std::string& name,
               const NodeConfig& conf,
               const RosNodeParams& params)
    : RosTopicSubNode<sensor_msgs::msg::BatteryState>(name, conf, params),
    is_battery_low_(true),
    is_battery_failure_(true)
  {}

  static BT::PortsList providedPorts()
  {
    return providedBasicPorts({InputPort<double>("min_battery")});
  }

  virtual BT::NodeStatus onTick(const sensor_msgs::msg::BatteryState::SharedPtr& last_msg) override;

  virtual void topicCallback(const std::shared_ptr<sensor_msgs::msg::BatteryState> msg) override;

private:

  bool is_battery_low_;
  bool is_battery_failure_;

};