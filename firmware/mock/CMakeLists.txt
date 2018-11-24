cmake_minimum_required(VERSION 3.0)
project(WatchDogeMock)

add_subdirectory(deps/sdl)

file(GLOB SOURCES src/*.cpp src/*/*.cpp)

add_executable(WatchDogeMock ${SOURCES})
target_include_directories(WatchDogeMock PUBLIC
        ${WatchDogeCommon_SOURCE_DIR}/include
        ${WatchDogeMock_SOURCE_DIR}/include
        ${DrMauro_SOURCE_DIR}/deps/sdl/include
)

if (MSVC)
    set_target_properties(WatchDogeMock PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
    set_target_properties(WatchDogeMock PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
    set_target_properties(WatchDogeMock PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
    set_target_properties(WatchDogeMock PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "_CONSOLE")
    set_target_properties(WatchDogeMock PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE")
    set_target_properties(WatchDogeMock PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:CONSOLE")
    target_link_libraries(
            WatchDogeMock
            WatchDogeCommon
            ${OpenCV_LIBS}
            SDL2
    )
else()
    target_link_libraries(
        WatchDogeMock
        WatchDogeCommon
        stdc++
        m
        ${OpenCV_LIBS}
        SDL2
    )
endif()
