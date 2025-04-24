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

function(build_one_test VERSION MODEL)
	foreach(TEST_SOURCE IN LISTS TEST_SOURCES)
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


set(VERSIONS "RPIPLC_V3" "RPIPLC_V4" "RPIPLC_V6" "UPSAFEPI_V6" "TOUCHBERRY_PI_V1" "GATEBERRY_V9")
set(RPIPLC_V6_MODELS "RPIPLC" "RPIPLC_19R" "RPIPLC_21" "RPIPLC_38AR" "RPIPLC_38R" "RPIPLC_42"
	"RPIPLC_50RRA" "RPIPLC_53ARR" "RPIPLC_54ARA" "RPIPLC_57AAR" "RPIPLC_57R" "RPIPLC_58")
set(RPIPLC_V4_MODELS ${RPIPLC_V6_MODELS})
set(RPIPLC_V3_MODELS ${RPIPLC_V6_MODELS})
set(UPSAFEPI_V6_MODELS "UPSAFEPI")
set(TOUCHBERRY_PI_V1_MODELS "TOUCHBERRY_PI")
set(GATEBERRY_V9_MODELS "GATEBERRY")


function(build_tests VERSION MODEL)
	if(VERSION STREQUAL "ALL")
		foreach(VERSION ${VERSIONS})
			if(VERSION STREQUAL "RPIPLC_V6")
				set(MODELS ${RPIPLC_V6_MODELS})
			elseif(VERSION STREQUAL "RPIPLC_V4")
				set(MODELS ${RPIPLC_V4_MODELS})
			elseif(VERSION STREQUAL "RPIPLC_V3")
				set(MODELS ${RPIPLC_V3_MODELS})
			elseif(VERSION STREQUAL "UPSAFEPI_V6")
				set(MODELS ${UPSAFEPI_V6_MODELS})
			elseif(VERSION STREQUAL "TOUCHBERRY_PI_V1")
				set(MODELS ${TOUCHBERRY_PI_V1_MODELS})
			elseif(VERSION STREQUAL "GATEBERRY_V9")
				set(MODELS ${GATEBERRY_V9_MODELS})
			endif()

			foreach(MODEL ${MODELS})
				build_one_test(${VERSION} ${MODEL})
			endforeach()
		endforeach()
	elseif(MODEL STREQUAL "ALL")
		if(VERSION STREQUAL "RPIPLC_V6")
			set(MODELS ${RPIPLC_V6_MODELS})
		elseif(VERSION STREQUAL "RPIPLC_V4")
			set(MODELS ${RPIPLC_V4_MODELS})
		elseif(VERSION STREQUAL "RPIPLC_V3")
			set(MODELS ${RPIPLC_V3_MODELS})
		elseif(VERSION STREQUAL "UPSAFEPI_V6")
			set(MODELS ${UPSAFEPI_V6_MODELS})
		elseif(VERSION STREQUAL "TOUCHBERRY_PI_V1")
			set(MODELS ${TOUCHBERRY_PI_V1_MODELS})
		elseif(VERSION STREQUAL "GATEBERRY_V9")
			set(MODELS ${GATEBERRY_V9_MODELS})
		endif()

		foreach(MODEL ${MODELS})
			build_one_test(${VERSION} ${MODEL})
		endforeach()
	else()
		build_one_test(${VERSION} ${MODEL})
	endif()
endfunction()

build_tests(${PLC_VERSION} ${PLC_MODEL} ${TEST_SOURCES})
