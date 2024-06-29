# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Set the project name and specify the language
project(MergeProject C)

# Define the source file(s)
set(SOURCE_FILES src/merge.c)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-O3)

# Specify the output directory for the binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Add the executable target
add_executable(merge ${SOURCE_FILES})
