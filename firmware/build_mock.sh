#!/bin/sh

mkdir mock_build
cd mock_build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
