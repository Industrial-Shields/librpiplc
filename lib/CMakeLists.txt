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

# Header files
include_directories(include)

# Source files
file(GLOB LIB_SOURCES "src/*.c")

add_library(${LIBNAME} SHARED ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(${LIBNAME} PROPERTIES LINKER_LANGUAGE C)

# Link with the plc-peripherals library
set(PLC_PERIPHERALS_LIB "${CMAKE_CURRENT_BINARY_DIR}/plc-peripherals-prefix/src/plc-peripherals-build/libplc-peripherals.a")
include(ExternalProject)
ExternalProject_Add(
	plc-peripherals
	GIT_REPOSITORY https://github.com/Industrial-Shields/plc-peripherals.git
	GIT_TAG v1.0.1
	GIT_SUBMODULES ""
	INSTALL_COMMAND ""
	CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_C_FLAGS="-fPIC"

	UPDATE_COMMAND ""
)
add_dependencies(${LIBNAME} plc-peripherals)
target_link_libraries(${LIBNAME} PRIVATE "-Wl,--whole-archive" ${PLC_PERIPHERALS_LIB} "-Wl,--no-whole-archive")



# Externalize the header files to other targets
target_include_directories(${LIBNAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	${CMAKE_CURRENT_BINARY_DIR}/plc-peripherals-prefix/src/plc-peripherals/include
	$<INSTALL_INTERFACE:include/lib${LIBNAME}>
)



# Install shared library
install(TARGETS ${LIBNAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
# And its header files
install(DIRECTORY include/ DESTINATION include/lib${LIBNAME}/include)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/plc-peripherals-prefix/src/plc-peripherals/include DESTINATION include/lib${LIBNAME}/include)
