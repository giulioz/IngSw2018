cmake_minimum_required(VERSION 3.0)
project(WatchDogeFirmware)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_executable(WatchDogeFirmware ${SOURCES} ${INCLUDES})
target_include_directories(WatchDogeFirmware PUBLIC
        ${WatchDogeFirmware_SOURCE_DIR}/include
        ${WatchDogeCommon_SOURCE_DIR}/include
        ${ev3dev-lang-cpp_SOURCE_DIR}
)
target_link_libraries(
        WatchDogeFirmware
        WatchDogeCommon
        stdc++
        m
        ev3dev::ev3dev
        ${OpenCV_LIBS}
)
