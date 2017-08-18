cmake_minimum_required(VERSION 2.8.3)
project(joy_node)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS joy roscpp rospy std_msgs genmsg message_generation)

## Declare ROS messages and services
add_message_files(FILES Controll.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker joy_node_generate_messages_cpp)
