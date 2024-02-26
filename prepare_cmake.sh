ROOT_DIR=$(dirname $(realpath "$0"))
BUILD_DIR=$ROOT_DIR/build
INSTALL_DIR=/tmp/librpiplc


BUILD_TYPE=""
DEBUG=""
PLC_VERSION=""
PLC_MODEL=""

for i in "$@"; do
    case $i in
	"-d"|"--debug")
	    DEBUG="-d"
	    shift
	    ;;
	"-V"[0-9])
	    if [[ "$1" =~ -V[3-5] ]]; then
		PLC_VERSION="RPIPLC_${1#-}"
		shift
	    else
		echo "Error: Version number is missing or incorrectly formatted. It must be -V5, -V4 or -V3"
		exit 1
	    fi
	    ;;
	"-M")
	    shift
	    if [[ $1 == "ALL" ]]; then
		PLC_MODEL="ALL"
	    else
		PLC_MODEL="RPIPLC_$1"
	    fi
	    CASCADE_ARGS="$CASCADE_ARGS $1"
	    shift
	    ;;
	"-VALL")
	    PLC_VERSION="ALL";
	    CASCADE_ARGS="$CASCADE_ARGS $1"
	    shift
	    ;;
	-*|--*)
	    echo "Unknown option $i. Usage: $0 [--debug] -V3|4|5 -M PLC_MODEL"
	    exit 1
	    ;;
	*)
	    ;;
    esac
done


if [ -n "$PLC_VERSION" ]; then
    PLC_VERSION="-DPLC_VERSION=$PLC_VERSION"
    PLC_MODEL="-DPLC_MODEL=$PLC_MODEL"
fi


rm -rf "$INSTALL_DIR"

mkdir "$INSTALL_DIR"


cmake -S "$ROOT_DIR" -B "$BUILD_DIR" $PLC_VERSION $PLC_MODEL -DCMAKE_BUILD_TYPE="$BUILD_TYPE" -DCMAKE_INSTALL_PREFIX="$INSTALL_DIR"
if [ $? -ne 0 ]; then
    echo "The command failed with exit code $?"
    exit 1
fi
