# HACK
set(CMAKE_C_COMPILER "arm-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-gcc")

cmake_minimum_required(VERSION 3.0)
project(RoboF)

add_subdirectory(deps/ev3dev-lang-cpp)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)
file(GLOB INCLUDE_DIRS include/*)
file(GLOB INCLUDES include/*.hpp include/*/*.hpp)

include_directories(
        ${RoboF_SOURCE_DIR}/include
        ${ev3dev-lang-cpp_SOURCE_DIR}
)

add_executable(RoboF ${SOURCES} ${INCLUDES})
target_link_libraries(
        RoboF
        stdc++
        m
        ev3dev::ev3dev
)
