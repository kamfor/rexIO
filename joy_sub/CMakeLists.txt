cmake_minimum_required(VERSION 2.8.3)
project(joy_sub)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg message_generation roslaunch)

## Declare ROS messages and services
add_message_files(FILES Controll.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

roslaunch_add_file_check(launch)

## Declare a catkin package
catkin_package(
#  INCLUDE_DIRS include
  CATKIN_DEPENDS message_runtime std_msgs
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener joy_sub_generate_messages_cpp)
