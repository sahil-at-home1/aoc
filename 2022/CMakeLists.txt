cmake_minimum_required(VERSION 3.2j.0)
project(aoc VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_TOOLCHAIN_FILE "./../vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

enable_testing()

find_package(GTest CONFIG REQUIRED)
    
add_library(Day7Lib 
    day7/day7/src/mydir.cpp 
    day7/day7/src/myfile.cpp 
    day7/day7/src/day7.cpp
    )

add_executable(Day7Main day7/main.cpp)
add_executable(Day7Test day7/test.cpp)

target_include_directories(Day7Lib PUBLIC day7/day7/include)
target_include_directories(Day7Main PUBLIC day7/day7/include)
target_include_directories(Day7Test PUBLIC day7/day7/include)


target_link_libraries(Day7Test PRIVATE GTest::gtest GTest::gtest_main Day7Lib)
target_link_libraries(Day7Main PRIVATE Day7Lib)

include(GoogleTest)
gtest_discover_tests(Day7Test)