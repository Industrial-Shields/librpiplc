ROOT_DIR=$(dirname $(realpath "$0"))
BUILD_DIR=$ROOT_DIR/build
INSTALL_DIR=/tmp/librpiplc

if [ "$#" -eq 3 ] && [ "$3" == "-d" ]; then
    DEBUG=-d
fi

if [ "$#" -lt 2 ] || [ "$#" -gt 3 ]; then
    echo "Usage: $0 PLC_VERSION PLC_MODEL [-d]"
    exit 1
fi

PLC_VERSION="$1"
PLC_MODEL="$2"


# Prepare CMake build infrastructure
"$ROOT_DIR/prepare_cmake.sh" "$PLC_VERSION" "$PLC_MODEL" "$DEBUG"


make -C "$BUILD_DIR" install

if [ -d "$INSTALL_DIR" ]; then
    sudo cp -r "$INSTALL_DIR/lib" /usr/local/
    sudo cp -r "$INSTALL_DIR/include" /usr/local/
    cp -r $INSTALL_DIR/test ~
else
    echo "Could not locate installation files. Aborting..."
    exit 1
fi
