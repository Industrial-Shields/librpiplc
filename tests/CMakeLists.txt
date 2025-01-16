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
file(GLOB TEST_SOURCES "src/*.cpp")

# Root directory where all tests will be
set(TESTS_OUTPUT_PATH "${CMAKE_BINARY_DIR}/test/")

function(build_one_test TEST_SOURCES VERSION MODEL)
	foreach(TEST_SOURCE ${TEST_SOURCES})
		# Get the base name of the test file without the extension
		get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

		set(FULL_TEST_NAME "${TEST_NAME}_${VERSION}_${MODEL}")


		add_executable(${FULL_TEST_NAME} ${TEST_SOURCE})

		add_dependencies(${FULL_TEST_NAME} ${LIBNAME})
		target_compile_options(${FULL_TEST_NAME} PRIVATE "${LIBRPIPLC_DEFAULT_COMPILE_FLAGS}")
		target_link_libraries(${FULL_TEST_NAME} ${LIBNAME})

		target_compile_definitions(${FULL_TEST_NAME} PUBLIC "${VERSION}" "${MODEL}")


		set_target_properties(${FULL_TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
			"${TESTS_OUTPUT_PATH}/${VERSION}/${MODEL}")
		set_target_properties(${FULL_TEST_NAME} PROPERTIES OUTPUT_NAME "${TEST_NAME}")


		if(CMAKE_BUILD_TYPE STREQUAL "DebPackage")
			install(TARGETS ${FULL_TEST_NAME} DESTINATION lib/librpiplc/${VERSION}/${MODEL})
		else()
			install(TARGETS ${FULL_TEST_NAME} DESTINATION $ENV{HOME}/test/${VERSION}/${MODEL})
		endif()
	endforeach()
endfunction()


foreach(VERSION ${VERSIONS_LIST})
	foreach(MODEL ${MODELS_LIST})
		build_one_test("${TEST_SOURCES}" "${VERSION}" "${MODEL}")
	endforeach()
endforeach()
