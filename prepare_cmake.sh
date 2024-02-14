ROOT_DIR=$(dirname $(realpath "$0"))
BUILD_DIR=$ROOT_DIR/build
INSTALL_DIR=/tmp/librpiplc

BUILD_TYPE=""
if [ "$#" -eq 3 ] && [ "$3" == "-d" ]; then
    BUILD_TYPE="Debug"
else
    BUILD_TYPE="Release"
fi


PLC_VERSION="$1"
PLC_MODEL="$2"



mkdir -p "$INSTALL_DIR"

cmake -S "$ROOT_DIR" -B "$BUILD_DIR" --install-prefix "$INSTALL_DIR" -DPLC_VERSION=$PLC_VERSION -DPLC_MODEL=$PLC_MODEL -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
