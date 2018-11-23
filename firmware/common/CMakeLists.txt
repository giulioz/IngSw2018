cmake_minimum_required(VERSION 3.0)
project(WatchDogeCommon)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_library(WatchDogeCommon STATIC
        ${SOURCES}
        ../deps/mongoose/mongoose.c
        ../deps/unqlite/unqlite.c
        ../deps/json/single_include/nlohmann/json.hpp)

target_include_directories(WatchDogeCommon PUBLIC
        ${WatchDogeCommon_SOURCE_DIR}/include
        ${WatchDogeCommon_SOURCE_DIR}/../deps/mongoose
        ${WatchDogeCommon_SOURCE_DIR}/../deps/unqlite
        ${WatchDogeCommon_SOURCE_DIR}/../deps/json/single_include
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(WatchDogeCommon ${OpenCV_LIBS})
