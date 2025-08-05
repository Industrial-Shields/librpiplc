#!/bin/sh
set -xeuo


DUMPER_ARGS="-all -loud -include-paths ./lib/include/;./build/lib/plc-peripherals-prefix/src/plc-peripherals/include/ -lver 4"


SCRIPT_DIR="$(realpath $(dirname '$0'))"
cd $SCRIPT_DIR

GIT_TAG=$(git describe --tags --exact-match)
if [ $? -ne 0 ]; then
    echo "No tag found for the current commit."
    exit 1
fi



rm -rf build/
cmake -B build/ -DCMAKE_BUILD_TYPE=Debug
cmake --build build/ -- -j $(nproc)
abi-dumper $DUMPER_ARGS build/lib/librpiplc.so -o "ABI Dumps/librpiplc-arm64-$GIT_TAG.abi"


export CC=arm-linux-gnueabihf-gcc
export LD_LIBRARY_PATH=/usr/lib/arm-linux-gnueabihf/
rm -rf build/
cmake -B build/ -DCMAKE_BUILD_TYPE=Debug
cmake --build build/ -- -j $(nproc)
abi-dumper $DUMPER_ARGS build/lib/librpiplc.so -o "ABI Dumps/librpiplc-armhf-$GIT_TAG.abi"
unset CC LD_LIBRARY_PATH
