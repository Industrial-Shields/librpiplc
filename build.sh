ROOT_DIR=$(dirname $(realpath "$0"))
BUILD_DIR=$ROOT_DIR/build
INSTALL_DIR=/tmp/librpiplc

INSTALL=""
DEBUG=""
PLC_VERSION=""
PLC_MODEL=""

CASCADE_ARGS=""

for i in "$@"; do
    case $i in
	"-i"|"--install")
	    INSTALL="install"
	    shift
	    ;;
	"-d"|"--debug")
	    DEBUG="-d"
	    CASCADE_ARGS="$CASCADE_ARGS $1"
	    shift
	    ;;
	"-V"[0-9])
	    if [[ "$i" =~ -V[3-5] ]]; then
		PLC_VERSION="RPIPLC_${1#-}"
		CASCADE_ARGS="$CASCADE_ARGS $1"
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
	    CASCADE_ARGS="$CASCADE_ARGS -M $1"
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


# Prepare CMake build infrastructure
"$ROOT_DIR/prepare_cmake.sh" $CASCADE_ARGS
if [ $? -ne 0 ]; then
    echo "Failed to prepare the CMake build infrastructure"
    exit 1
fi

# Build the install target
make -j$(nproc --all) -C "$BUILD_DIR" $INSTALL
if [ $? -ne  0 ]; then
    echo "Failed to build librpiplc. The process exited with code $?"
    exit 1
fi

# Copy all new files
if [ -n "$INSTALL" ]; then
    if [ -d "$INSTALL_DIR" ]; then
	sudo cp -r "$INSTALL_DIR/lib" /usr/local/
	sudo cp -r "$INSTALL_DIR/include" /usr/local/
	if [ -d $INSTALL_DIR/test ]; then
	    echo "Installing tests..."
	    cp -r $INSTALL_DIR/test ~
	fi
    else
	echo "Could not locate installation files. Aborting..."
	exit 1
    fi
fi
