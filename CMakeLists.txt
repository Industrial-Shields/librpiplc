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

# Set C and C++ standards
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

# Enable some warning flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fanalyzer")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fanalyzer")
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

# Determine build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g -fno-omit-frame-pointer")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_C_FLAGS_DEBUG}")
else()
	# Change -O3 optimization to -O2
	string(REPLACE "-O3" "-O2" CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_RELEASE}")
endif()


# Enable compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Name of the library
set(LIBNAME rpiplc)


# If is not an out of source build, cause fatal error to
# stop the script from further execution
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "CMake has been ran to create an out of source build.
This error prevents CMake from running an in-source build.")
endif ()


# Check that if the PLC version and model macros are passed are correct
set(VERSIONS_LIST RPIPLC_V3 RPIPLC_V4 RPIPLC_V5)
set(MODELS_LIST RPIPLC RPIPLC_19R RPIPLC_21 RPIPLC_38AR RPIPLC_38R RPIPLC_42
	RPIPLC_50RRA RPIPLC_53ARR RPIPLC_54ARA RPIPLC_57AAR RPIPLC_57R RPIPLC_58)

if(DEFINED PLC_VERSION OR DEFINED PLC_MODEL)
	# Check that they are correct
	if(NOT PLC_VERSION STREQUAL "ALL" AND NOT PLC_VERSION IN_LIST VERSIONS_LIST)
		message(FATAL_ERROR "Invalid value for PLC_VERSION: ${PLC_VERSION}")
	elseif(NOT PLC_MODEL STREQUAL "ALL" AND NOT PLC_MODEL IN_LIST MODELS_LIST)
		message(FATAL_ERROR "Invalid value for PLC_MODEL: ${PLC_MODEL}")
	endif()
endif()


# Add the librpiplc CMakeLists.txt
add_subdirectory(lib)

# Add the tests CMakeLists.txt only if version and model is given
if(DEFINED PLC_VERSION AND DEFINED PLC_MODEL)
	if(NOT PLC_VERSION STREQUAL "ALL")
		set(VERSIONS_LIST ${PLC_VERSION})
	endif()
	if(NOT PLC_MODEL STREQUAL "ALL")
		set(MODELS_LIST ${PLC_MODEL})
	endif()

	add_subdirectory(tests)
endif()
