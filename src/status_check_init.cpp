#include "status_check_init.hpp"

BT_REGISTER_NODES(factory)
{
    RegisterNodes(factory);
}

BT::NodeStatus StatusCheckInit::tick()
{
    //std::cout << "Hello" << std::endl;
    return BT::NodeStatus::SUCCESS;
}