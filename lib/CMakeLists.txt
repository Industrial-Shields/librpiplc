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
	GIT_TAG HEAD
	GIT_SUBMODULES ""
	INSTALL_COMMAND ""

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
install(DIRECTORY include/ DESTINATION include/lib${LIBNAME})
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/plc-peripherals-prefix/src/plc-peripherals/include DESTINATION include/lib${LIBNAME})
