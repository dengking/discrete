cmake_minimum_required(VERSION 3.19)
project(test VERSION 1.0.0 LANGUAGES CXX)


# Add a testing executable
add_executable(disjoint_set disjoint_set.cpp)

target_compile_features(disjoint_set PRIVATE cxx_std_20)


