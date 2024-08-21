cmake_minimum_required(VERSION 3.10)
project(hayutils)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to building a static library
option(SHARED_utils "Build hayutils as a shared library" OFF)
option(BUILD_tests "Build tests" ON)

# Define the library name
set(LIBRARY_NAME "hayutils")

# Source files for the library
set(SOURCES
    src/utils.c
    # Add additional source files here if needed
)

# Include directories
include_directories(include)

# Create the library
if(SHARED_utils)
    add_library(${LIBRARY_NAME} SHARED ${SOURCES})
else()
    add_library(${LIBRARY_NAME} STATIC ${SOURCES})
endif()

# Link the math library
target_link_libraries(${LIBRARY_NAME} PRIVATE m)

# Set the version for shared libraries
if(SHARED_utils)
    set_target_properties(${LIBRARY_NAME} PROPERTIES
        VERSION 1.0
        SOVERSION 1
    )
endif()

# Install targets
install(TARGETS ${LIBRARY_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# Install headers
install(DIRECTORY include/ DESTINATION include)

if(BUILD_tests)
    # Enable testing
    enable_testing()

    # Collect all test files
    file(GLOB TEST_SOURCES "tests/test_*.c")

    # Create a separate executable for each test file
    foreach(test_file ${TEST_SOURCES})
        # Extract the filename without the extension
        get_filename_component(test_name ${test_file} NAME_WE)
        # Define the executable
        add_executable(${test_name} ${test_file})
        # Link the executable with the library and the math library
        target_link_libraries(${test_name} PRIVATE ${LIBRARY_NAME} m)
        # Define the test case
        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
endif()
