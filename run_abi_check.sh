#!/bin/sh
set -xeuo


DUMPER_ARGS="-all -loud -include-paths ./lib/include/;./build/lib/plc-peripherals-prefix/src/plc-peripherals/include/ -lver 5"
LIBNAME=librpiplc
MAIN_DIR=/tmp/abi-check


LAST_GIT_TAG=$(git describe --tags --abbrev=0)
LIBVERSION=$LAST_GIT_TAG

SCRIPT_DIR="$(realpath $(dirname '$0'))"
ORIGINAL_DIR="$(pwd)"


ARM64_DIR="$MAIN_DIR/$LIBNAME-abi-check-arm64"

OLD_ARM64_ABI_NAME="$LIBNAME-arm64-$LIBVERSION.abi"
OLD_ARM64_ABI_DUMP="$SCRIPT_DIR/ABI Dumps/$OLD_ARM64_ABI_NAME"
OLD_ARM64_ABI_DUMP_SYMLINK="$MAIN_DIR/$OLD_ARM64_ABI_NAME"

NEW_ARM64_ABI_NAME="$LIBNAME-arm64.abi"
NEW_ARM64_ABI_DUMP="$MAIN_DIR/$NEW_ARM64_ABI_NAME"


ARMHF_DIR="$MAIN_DIR/$LIBNAME-abi-check-armhf"

OLD_ARMHF_ABI_NAME="$LIBNAME-armhf-$LIBVERSION.abi"
OLD_ARMHF_ABI_DUMP="$SCRIPT_DIR/ABI Dumps/$OLD_ARMHF_ABI_NAME"
OLD_ARMHF_ABI_DUMP_SYMLINK="$MAIN_DIR/$OLD_ARMHF_ABI_NAME"

NEW_ARMHF_ABI_NAME="$LIBNAME-armhf.abi"
NEW_ARMHF_ABI_DUMP="$MAIN_DIR/$NEW_ARMHF_ABI_NAME"



rm -rf "$MAIN_DIR"
mkdir -p "$ARM64_DIR" "$ARMHF_DIR"



# Check arm64 build first
cmake -B "$ARM64_DIR" "$SCRIPT_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$ARM64_DIR" -- -j $(nproc)

abi-dumper $DUMPER_ARGS $ARM64_DIR/lib/$LIBNAME.so -o "$NEW_ARM64_ABI_DUMP"

# Then armhf build
export CC=arm-linux-gnueabihf-gcc
export LD_LIBRARY_PATH=/usr/lib/arm-linux-gnueabihf/
cmake -B "$ARMHF_DIR" "$SCRIPT_DIR" -DCMAKE_BUILD_TYPE=Debug
cmake --build "$ARMHF_DIR" -- -j $(nproc)

abi-dumper $DUMPER_ARGS $ARMHF_DIR/lib/$LIBNAME.so -o "$NEW_ARMHF_ABI_DUMP"

unset CC LD_LIBRARY_PATH

cd "$MAIN_DIR"
abi-compliance-checker -l "$LIBNAME-$LIBVERSION-arm64-report" -s -old "$OLD_ARM64_ABI_DUMP" -new "$NEW_ARM64_ABI_DUMP" || true
abi-compliance-checker -l "$LIBNAME-$LIBVERSION-armhf-report" -old "$OLD_ARMHF_ABI_DUMP" -new "$NEW_ARMHF_ABI_DUMP" || true



python -m http.server --directory $MAIN_DIR
