cmake_minimum_required(VERSION 3.0)
project(WatchDogeMock)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_executable(WatchDogeMock ${SOURCES})
target_include_directories(WatchDogeMock PUBLIC
        ${WatchDogeCommon_SOURCE_DIR}/include
        ${WatchDogeMock_SOURCE_DIR}/include
)
target_link_libraries(
        WatchDogeMock
        WatchDogeCommon
        stdc++
        m
        ${OpenCV_LIBS}
)
