# Header files
include_directories(include)

# Source files
file(GLOB TEST_SOURCES "src/*.cpp")

# Find the rpiplc library
find_library(${LIBNAME} NAMES ${LIBNAME})


# Root directory where all tests will be
set(TESTS_OUTPUT_PATH "${CMAKE_BINARY_DIR}/test/")


function(build_one_test TEST_SOURCES VERSION MODEL)
	foreach(TEST_SOURCE ${TEST_SOURCES})
		# Get the base name of the test file without the extension
		get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

		set(FULL_TEST_NAME "${TEST_NAME}_${VERSION}_${MODEL}")


		add_executable(${FULL_TEST_NAME} ${TEST_SOURCE})

		target_link_libraries(${FULL_TEST_NAME} ${LIBNAME})

		target_compile_definitions(${FULL_TEST_NAME} PUBLIC "${VERSION}" "${MODEL}")


		set_target_properties(${FULL_TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
			"${TESTS_OUTPUT_PATH}/${VERSION}/${MODEL}")
		set_target_properties(${FULL_TEST_NAME} PROPERTIES OUTPUT_NAME "${TEST_NAME}")


		install(TARGETS ${FULL_TEST_NAME} DESTINATION $ENV{HOME}/test/${VERSION}/${MODEL})
	endforeach()
endfunction()


foreach(VERSION ${VERSIONS_LIST})
	foreach(MODEL ${MODELS_LIST})
		build_one_test("${TEST_SOURCES}" "${VERSION}" "${MODEL}")
	endforeach()
endforeach()
