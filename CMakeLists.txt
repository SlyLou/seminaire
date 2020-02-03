cmake_minimum_required(VERSION 2.8.3)
project(seminaire)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  std_msgs
  message_generation
)

add_message_files(
  DIRECTORY
  msg
  
  FILES
  Encoders.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

# add_executable(odom src/nodes/MotorControl/odom.cpp)
# target_link_libraries(odom ${catkin_LIBRARIES})
# add_dependencies(odom heron_generate_messages_cpp)