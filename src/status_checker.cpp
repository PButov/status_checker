#include <iostream>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/executors.hpp>

#include "behaviortree_cpp/bt_factory.h"
#include "status_check_init.hpp"
#include "battery_check.hpp"


using namespace BT;

int main(int argc, char * argv[])
{

    rclcpp::init(argc, argv);

    BehaviorTreeFactory factory;

    factory.registerNodeType<StatusCheckInit>("StatusCheckInit");

    auto nh = std::make_shared<rclcpp::Node>("battery_check");
  
    RosNodeParams params;
    params.nh = nh;
    params.default_port_value = "battery_charge";

    factory.registerNodeType<BatteryCheck>("BatteryCheck", params);

    auto tree = factory.createTreeFromFile("/home/ws/src/status_checker/src/status_checker_tree.xml");

    while (true)
    {
        tree.tickWhileRunning();
        //sleep(0.1);
    }
  
    //rclcpp::shutdown();
    return 0;
    
}
