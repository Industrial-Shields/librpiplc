cmake_minimum_required(VERSION 3.25.1-1)
project("RPi PLC GPIO Control")

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Name of the library
set(LIBNAME rpiplc)


# If is not an out of source build, cause fatal error to
# stop the script from further execution
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "CMake has been ran to create an out of source build.
This error prevents CMake from running an in-source build.")
endif ()


# Check that both the PLC version and model macros are passed
set(VERSIONS_LIST RPIPLC_V3 RPIPLC_V4)
set(MODELS_LIST RPIPLC_19R RPIPLC_21 RPIPLC_38AR RPIPLC_38R RPIPLC_42
	RPIPLC_50RRA RPIPLC_53ARR PIPLC_54ARA RPIPLC_57AAR RPIPLC_57R RPIPLC_58)

if(NOT DEFINED PLC_VERSION OR NOT DEFINED PLC_MODEL)
	message(FATAL_ERROR "Usage: cmake -DPLC_VERSION=<value> -DPLC_MODEL=<value>")
endif()

# .. and that they are correct
if(NOT "${PLC_VERSION}" STREQUAL "ALL" AND NOT "${PLC_VERSION}" IN_LIST VERSIONS_LIST)
	message(FATAL_ERROR "Invalid value for PLC_VERSION")
endif()
if(NOT "${PLC_MODEL}" STREQUAL "ALL" AND NOT "${PLC_MODEL}" IN_LIST MODELS_LIST)
	message(FATAL_ERROR "Invalid value for PLC_MODEL")
endif()

# And if the version and model are not "ALL", make a list of one element
if(NOT PLC_VERSION STREQUAL "ALL")
    set(VERSIONS_LIST ${PLC_VERSION})
endif()
if(NOT PLC_MODEL STREQUAL "ALL")
    set(MODELS_LIST ${PLC_MODEL})
endif()


# Add the librpiplc CMakeLists.txt
add_subdirectory(lib)

# Add the tests CMakeLists.txt
add_subdirectory(test)
