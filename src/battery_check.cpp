#include "battery_check.hpp"

using namespace BT;

BT::NodeStatus BatteryCheck::onTick(const std_msgs::msg::Float32::SharedPtr& last_msg){

    if(battery_charge_ >= 0 && battery_charge_ < 100){
        if(battery_charge_ < 50){
            std::cout << "Bateery check failed: charge the battery!" << std::endl;
            return BT::NodeStatus::FAILURE;
        }
        else{
            std::cout << "Bateery check complited successfully" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }
    }

    std::cout << "Data about battery charge is unavailible or incorrect" << std::endl;
    return BT::NodeStatus::FAILURE;
    
}

void BatteryCheck::topicCallback(const std::shared_ptr<std_msgs::msg::Float32> msg) {
    battery_charge_ = msg->data;
}
