cmake_minimum_required(VERSION 2.8.3)
project(performance_tests)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp 
	rospy 
	std_msgs
	message_generation
)

## Declare ROS messages and services
add_message_files(
	FILES 
	SuperAwesome.msg
)

## Generate added messages and services
generate_messages(
	DEPENDENCIES 
	std_msgs
)


## Declare a catkin package
catkin_package(
	CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ${PROJECT_NAME}_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener ${PROJECT_NAME}_generate_messages_cpp)