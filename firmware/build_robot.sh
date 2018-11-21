#!/bin/sh

mkdir robot_build
cd robot_build
CC=arm-linux-gnueabi-gcc CXX=CC=arm-linux-gnueabi-gcc cmake -DROBOT=ON -DSOFTFP=ON -DCMAKE_TOOLCHAIN_FILE=deps/opencv/platforms/linux/arm-gnueabi.toolchain.cmake ..
make
