<<<<<<< HEAD
=======
<<<<<<< HEAD
#!/bin/sh

mkdir robot_build
cd robot_build
CC=arm-linux-gnueabi-gcc CXX=CC=arm-linux-gnueabi-gcc cmake -DROBOT=ON -DSOFTFP=ON -DCMAKE_TOOLCHAIN_FILE=deps/opencv/platforms/linux/arm-gnueabi.toolchain.cmake ..
make
=======
>>>>>>> asdf
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
<<<<<<< HEAD
=======
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
>>>>>>> asdf
