cmake_minimum_required(VERSION 3.16)
project(status_checker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED )
find_package(std_msgs REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)

# add executables

add_executable(
  status_checker
  src/status_checker.cpp 
  src/status_check_init.cpp
  src/battery_check.cpp)

ament_target_dependencies(status_checker rclcpp std_msgs behaviortree_cpp behaviortree_ros2) 

# install

install(TARGETS
  status_checker
  DESTINATION lib/${PROJECT_NAME})

ament_package()
