cmake_minimum_required(VERSION 3.25.0)
project(aoc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x86-windows/")

find_package(GTest CONFIG REQUIRED)

add_library(day7 day7/day7.cpp)
add_executable(day7_main day7/main.cpp)
add_executable(day7_test day7/test.cpp)

enable_testing()

target_link_libraries(day7_test PRIVATE GTest::gtest GTest::gtest_main day7)
target_link_libraries(day7_main PRIVATE day7)

add_test(day7_test day7)