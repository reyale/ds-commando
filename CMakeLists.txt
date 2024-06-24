# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the language
project(MergeProject C)

# Specify the C++ standard
##set(CMAKE_CXX_STANDARD 11)
##set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the source file(s)
set(SOURCE_FILES src/merge.c)

# Specify the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Add the executable target
add_executable(merge ${SOURCE_FILES})
