# Copyright (c) 2024 Industrial Shields. All rights reserved
#
# This file is part of librpiplc.
#
# librpiplc is free software: you can redistribute
# it and/or modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either version
# 3 of the License, or (at your option) any later version.
#
# librpiplc is distributed in the hope that it will
# be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.18.4)
project("RPi PLC GPIO Control")

# Name of the library
set(LIBNAME rpiplc)

# Set C and C++ standards
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Enable some warning flags, and force them as errors
if(NOT LIBRPIPLC_DEFAULT_COMPILE_FLAGS)
	set(LIBRPIPLC_DEFAULT_COMPILE_FLAGS
		-Wall
		-Wextra
		-fanalyzer
		-Werror
	)
endif()
# Force PIE executables
include(CheckPIESupported)
check_pie_supported() # If not called, -pie is not passed to the linker
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)


# Determine build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions("DEBUG")
	list(APPEND LIBRPIPLC_DEFAULT_COMPILE_FLAGS -Werror -Og -g -fno-omit-frame-pointer)
else()
	add_compile_definitions("NDEBUG")
	# Change -O3 optimization to -O2
	string(REPLACE "-O3" "-O2" LIBRPIPLC_DEFAULT_COMPILE_FLAGS "${LIBRPIPLC_DEFAULT_COMPILE_FLAGS}")
endif()


# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# If is not an out of source build, cause fatal error to
# stop the script from further execution
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "CMake has been ran to create an out of source build.
This error prevents CMake from running an in-source build.")
endif ()


# Add the librpiplc CMakeLists.txt
add_subdirectory(lib)


# Add the tests CMakeLists.txt only if version and model is given
if(DEFINED PLC_VERSION AND DEFINED PLC_MODEL)
	add_subdirectory(tests)
endif()
