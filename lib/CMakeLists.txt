# Header files
include_directories(include)

# Source files
file(GLOB LIB_SOURCES "src/*.c")

add_library(${LIBNAME} SHARED ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(${LIBNAME} PROPERTIES LINKER_LANGUAGE C)

# Link with the plc-peripherals library
set(PLC_PERIPHERALS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/plc-peripherals")
include_directories(${PLC_PERIPHERALS_DIR}/include)
execute_process(
    COMMAND make clean
    WORKING_DIRECTORY ${PLC_PERIPHERALS_DIR}
)
execute_process(
    COMMAND make -j4 with_expanded_gpio EXTRA_CFLAGS=-fPIC
    WORKING_DIRECTORY ${PLC_PERIPHERALS_DIR}
)
find_library(PLC_PERIPHERALS_LIB
             NAMES plc-peripherals
             PATHS ${PLC_PERIPHERALS_DIR}/build)
target_link_libraries(${LIBNAME} PRIVATE -Wl,--whole-archive ${PLC_PERIPHERALS_LIB} -Wl,--no-whole-archive)


# Externalize the header files to other targets
target_include_directories(${LIBNAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${PLC_PERIPHERALS_DIR}/include>
	$<INSTALL_INTERFACE:include/lib${LIBNAME}>
)



# Install shared library
install(TARGETS ${LIBNAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)
# And its header files
install(DIRECTORY include/ DESTINATION include/lib${LIBNAME})
install(DIRECTORY ${PLC_PERIPHERALS_DIR}/include/ DESTINATION include/lib${LIBNAME})
