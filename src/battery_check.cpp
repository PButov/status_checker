#include "battery_check.hpp"

using namespace BT;

BT::NodeStatus BatteryCheck::onTick(const sensor_msgs::msg::BatteryState::SharedPtr& last_msg){

    if(!is_battery_failure_){

        if(is_battery_low_){
            std::cout << "Battery check failed: charge the battery!" << std::endl;
            return BT::NodeStatus::FAILURE;
        }
        else{
            std::cout << "Battery check complited successfully" << std::endl;
            return BT::NodeStatus::SUCCESS;
        }

    }

    std::cout << "Data about battery charge is unavailible or incorrect" << std::endl;
    return BT::NodeStatus::FAILURE;
    
}

void BatteryCheck::topicCallback(const std::shared_ptr<sensor_msgs::msg::BatteryState> msg) {
    
    double battery_percentage = msg->percentage;
    double min_battery_percentage = getInput<double>("min_battery").value();
    
    is_battery_failure_ = false;

    if(battery_percentage >= 0 && battery_percentage < 100){
        if(battery_percentage < min_battery_percentage){
            is_battery_low_ = true;
        }
        else{
            is_battery_low_ = false;
        }
    }
    else {
        is_battery_failure_ = true;
    }

}
