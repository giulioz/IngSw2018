<<<<<<< HEAD
=======
<<<<<<< HEAD
#!/bin/sh

mkdir mock_build
cd mock_build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
=======
>>>>>>> asdf
#!/bin/sh

mkdir mock_build
cd mock_build
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_DOCS=OFF \
    -DBUILD_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_PERF_TESTS=OFF \
    -DWITH_CUDA=OFF \
    ..
make
<<<<<<< HEAD
=======
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
>>>>>>> asdf
