cmake_minimum_required(VERSION 3.25.0)
project(aoc VERSION 0.1.0 LANGUAGES C CXX)

add_library(day7 day7/day7.cpp)
add_executable(day7_main day7/main.cpp)

enable_testing()

find_package(GTest CONFIG REQUIRED)
target_link_libraries(day7 PRIVATE GTest::gtest GTest::gtest_main )

add_test(day7test day7)