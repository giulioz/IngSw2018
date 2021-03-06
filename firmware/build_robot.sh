#!/bin/sh

mkdir robot_build
cd robot_build
CC=arm-linux-gnueabi-gcc CXX=CC=arm-linux-gnueabi-gcc cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_DOCS=OFF \
    -DBUILD_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_PERF_TESTS=OFF \
    -DROBOT=ON \
    -DSOFTFP=ON \
    -DCMAKE_TOOLCHAIN_FILE=deps/opencv/platforms/linux/arm-gnueabi.toolchain.cmake \
    ..
make