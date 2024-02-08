# Header files
include_directories(include)

# Source files
file(GLOB LIB_SOURCES "src/*.cpp")



add_library(${LIBNAME} SHARED ${LIB_SOURCES} ${LIB_HEADERS})

set_target_properties(${LIBNAME} PROPERTIES LINKER_LANGUAGE CXX)


# Externalize the header files to other targets
target_include_directories(${LIBNAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
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
