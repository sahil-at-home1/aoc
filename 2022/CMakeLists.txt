cmake_minimum_required(VERSION 3.25.0)
project(aoc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x86-windows/")

find_package(GTest CONFIG REQUIRED)

add_library(day7 day7/day7.cpp)
add_executable(Day7Main day7/main.cpp)
add_executable(Day7Test day7/test.cpp)

enable_testing()

target_link_libraries(Day7Test PRIVATE GTest::gtest GTest::gtest_main day7)
target_link_libraries(Day7Main PRIVATE day7)

include(GoogleTest)
gtest_discover_tests(Day7Test)