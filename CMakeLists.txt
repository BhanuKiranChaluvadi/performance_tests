cmake_minimum_required(VERSION 2.8.3)
project(performance_tests)

find_package(catkin REQUIRED COMPONENTS std_msgs roscpp rospy message_generation)

add_message_files(FILES SuperAwesome.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime std_msgs )

include_directories(include ${catkin_INCLUDE_DIRS})

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/simple_publisher.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker simple_publisher)

add_executable(listener src/simple_subscriber.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener simple_subscriber)