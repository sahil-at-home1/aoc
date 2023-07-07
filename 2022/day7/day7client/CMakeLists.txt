cmake_minimum_required(VERSION 3.21.0)
project(Day7Client VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_TOOLCHAIN_FILE "C:/Users/sahil/dev/aoc/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

enable_testing()

find_package(GTest CONFIG REQUIRED)

add_executable(Day7Main main.cpp)
add_executable(Day7Test test.cpp)

target_link_libraries(Day7Main LINK_PUBLIC Day7Lib)
target_link_libraries(Day7Test LINK_PUBLIC GTest::gtest GTest::gtest_main Day7Lib)

target_include_directories(Day7Main PUBLIC day7lib/include)
target_include_directories(Day7Test PUBLIC day7lib/include)

include(GoogleTest)
gtest_discover_tests(Day7Test)

