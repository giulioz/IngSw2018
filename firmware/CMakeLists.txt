cmake_minimum_required(VERSION 3.0)
project(WatchDogeFirmware)

add_subdirectory(deps/opencv)

set (CMAKE_CXX_STANDARD 11)

if(ROBOT)
add_subdirectory(deps/ev3dev-lang-cpp)
endif()

add_subdirectory(common)

if(ROBOT)
add_subdirectory(robot)
else()
add_subdirectory(mock)
endif()
