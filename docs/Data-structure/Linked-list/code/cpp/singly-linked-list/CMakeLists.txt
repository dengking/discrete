cmake_minimum_required(VERSION 3.19)
project(singly-linked-list VERSION 1.0.0 LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(unit_tests unit_tests.cpp)

target_compile_features(unit_tests PRIVATE cxx_std_11)

target_link_libraries(unit_tests ${CONAN_LIBS})

add_test(test_all unit_tests)
