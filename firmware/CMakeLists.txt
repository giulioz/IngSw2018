cmake_minimum_required(VERSION 3.0)
project(WatchDogeFirmware)

add_subdirectory(deps/opencv)

if(ROBOT)
add_subdirectory(deps/ev3dev-lang-cpp)
endif()

add_subdirectory(common)

if(MOCK)
add_subdirectory(mock)
endif()

if(ROBOT)
add_subdirectory(robot)
endif()
