#include "behaviortree_cpp/behavior_tree.h"
#include "behaviortree_cpp/bt_factory.h"

using BT::NodeStatus;

class StatusCheckInit : public BT::SyncActionNode
{
  public:
    StatusCheckInit(const std::string& name) :
        BT::SyncActionNode(name, {})
    {
    }

    NodeStatus tick() override;
};

inline void RegisterNodes(BT::BehaviorTreeFactory& factory)
{
    factory.registerNodeType<StatusCheckInit>("StatusCheckInit");
}