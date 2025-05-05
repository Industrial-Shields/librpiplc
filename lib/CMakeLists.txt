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

# librpiplc header and source files
file(GLOB LIB_HEADERS "include/*.h")
file(GLOB LIB_SOURCES "src/*.c")


# Add plc-peripherals as external project
include(ExternalProject)
ExternalProject_Add(
	plc-peripherals
	GIT_REPOSITORY https://github.com/Industrial-Shields/plc-peripherals.git
	GIT_TAG new-pins-enum
	# SOURCE_DIR /home/pi/plc-peripherals
	GIT_SUBMODULES ""
	INSTALL_COMMAND ""
	CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER} -DCMAKE_LINKER=${CMAKE_LINKER}
	UPDATE_COMMAND ""
)
ExternalProject_Get_Property(plc-peripherals SOURCE_DIR BINARY_DIR)


add_library(${LIBNAME} SHARED ${LIB_SOURCES})
target_include_directories(${LIBNAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	${CMAKE_CURRENT_BINARY_DIR}/plc-peripherals-prefix/src/plc-peripherals/include
	# /home/pi/plc-peripherals/include
	$<INSTALL_INTERFACE:include/lib${LIBNAME}>
)
target_compile_options(${LIBNAME} PRIVATE ${LIBRPIPLC_DEFAULT_COMPILE_FLAGS})
target_link_options(${LIBNAME} PRIVATE
    -Wl,--whole-archive
    ${BINARY_DIR}/libplc-peripherals.a
    -Wl,--no-whole-archive
)
add_dependencies(${LIBNAME} plc-peripherals)


# Must be a matching pattern, because files are downloaded during the build process
install(DIRECTORY ${SOURCE_DIR}/include/ DESTINATION include COMPONENT headers FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include COMPONENT headers FILES_MATCHING PATTERN "*.h")
install(TARGETS ${LIBNAME} DESTINATION lib)


set_target_properties(${LIBNAME} PROPERTIES
  PUBLIC_HEADER "rpiplc.h"
  VERSION 4.0.0
  SOVERSION 4
)
