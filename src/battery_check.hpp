#include <behaviortree_ros2/bt_topic_sub_node.hpp>
#include "std_msgs/msg/float32.hpp"

using namespace BT;

class BatteryCheck: public RosTopicSubNode<std_msgs::msg::Float32>
{
public:

  BatteryCheck(const std::string& name,
               const NodeConfig& conf,
               const RosNodeParams& params)
    : RosTopicSubNode<std_msgs::msg::Float32>(name, conf, params)
  {}

  static BT::PortsList providedPorts()
  {
    return providedBasicPorts({});
  }

  virtual BT::NodeStatus onTick(const std_msgs::msg::Float32::SharedPtr& last_msg) override;

  virtual void topicCallback(const std::shared_ptr<std_msgs::msg::Float32> msg) override;

private:

  float battery_charge_ = -1;

};