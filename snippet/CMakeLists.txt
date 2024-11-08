cmake_minimum_required(VERSION 3.5)


project(snippet)

# Find GTest from vcpkg
find_package(GTest CONFIG REQUIRED)

# Include GTest headers
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(snippet_print_reverse_order print_reverse_order.cpp)
add_executable(snippet_measure_time measure_time.cpp)
add_executable(matrix_times_vector matrix_times_vector.cpp)

target_link_libraries(matrix_times_vector PRIVATE GTest::gtest GTest::gtest_main)
