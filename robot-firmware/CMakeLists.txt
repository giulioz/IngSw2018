# HACK
set(CMAKE_C_COMPILER "arm-linux-gnueabi-gcc")
set(CMAKE_CXX_COMPILER "arm-linux-gnueabi-gcc")
set(EV3DEV_PLATFORM "EV3")

cmake_minimum_required(VERSION 3.0)
project(RoboF)

add_subdirectory(deps/opencv)
add_subdirectory(deps/ev3dev-lang-cpp)

file(GLOB SOURCES src/*.cpp src/*/*.cpp  deps/mongoose/mongoose.c)
file(GLOB INCLUDE_DIRS include/*)
file(GLOB INCLUDES include/*.hpp include/*/*.hpp)

include_directories(
        ${RoboF_SOURCE_DIR}/include
        ${RoboF_SOURCE_DIR}/deps/mongoose
        ${ev3dev-lang-cpp_SOURCE_DIR}
)

add_executable(RoboF ${SOURCES} ${INCLUDES})
target_link_libraries(
        RoboF
        stdc++
        m
        ev3dev::ev3dev
        ${OpenCV_LIBS}
)
