cmake_minimum_required(VERSION 3.0)
project(WatchDogeCommon)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_library(WatchDogeCommon ${SOURCES} ../deps/mongoose/mongoose.c ../deps/unqlite/unqlite.c)
target_include_directories(WatchDogeCommon PUBLIC
        ${WatchDogeCommon_SOURCE_DIR}/include
        ${WatchDogeCommon_SOURCE_DIR}/../deps/mongoose
        ${WatchDogeCommon_SOURCE_DIR}/../deps/unqlite
)
