#!/bin/sh

mkdir mock_build
cd mock_build
cmake -DMOCK=ON ..
make
