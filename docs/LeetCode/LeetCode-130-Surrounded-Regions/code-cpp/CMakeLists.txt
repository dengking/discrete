# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 20)

# Set the project name
project (solution)

# Add an executable
add_executable(solution solution.cpp)
