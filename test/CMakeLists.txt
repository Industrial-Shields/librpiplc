# Header files
include_directories(include)

# Source files
file(GLOB TEST_SOURCES "src/*.cpp")

# Find the rpiplc library
find_library(${LIBNAME} NAMES ${LIBNAME})

# Add the macros to the tests
add_definitions(-D"${PLC_VERSION}")
add_definitions(-D"${PLC_MODEL}")

# Create an executable for each test source file
foreach(TEST_SOURCE ${TEST_SOURCES})
	# Get the base name of the test file without the extension
	get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

	add_executable(${TEST_NAME} ${TEST_SOURCE})

	target_link_libraries(${TEST_NAME} ${LIBNAME})
endforeach()
