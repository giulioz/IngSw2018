#!/bin/sh

mkdir mock_build
cd mock_build
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_DOCS=OFF \
    -DBUILD_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_PERF_TESTS=OFF \
    ..
make
