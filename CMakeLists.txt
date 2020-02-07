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
  winch.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)


include_directories(include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${GSTREAMER_INCLUDE_DIRS})
  

add_executable(plate_DigitalTwin src/nodes/plate_DigitalTwin.cpp)
target_link_libraries(plate_DigitalTwin ${catkin_LIBRARIES})
add_dependencies(plate_DigitalTwin seminaire_generate_messages_cpp)