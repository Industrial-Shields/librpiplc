#!/bin/bash

set -euo

SIGN_KEY=5AD8FD2E2EF303FD7FAD59938356C65F95C75269

ARCH=$1

if [[ "$ARCH" == "armhf" ]]; then
    export CC=arm-linux-gnueabihf-gcc
    export CXX=arm-linux-gnueabihf-g++
else
    export CC=aarch64-linux-gnu-gcc
    export CXX=aarch64-linux-gnu-g++
fi

export $(dpkg-architecture -a$ARCH)

export LD_LIBRARY_PATH="/lib/$DEB_TARGET_MULTIARCH/:/usr/$DEB_TARGET_MULTIARCH/lib/"
dpkg-buildpackage --host-arch $ARCH --sign-key=$SIGN_KEY -j$(nproc) -b
