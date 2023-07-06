cmake_minimum_required(VERSION 3.21.0)
project(Day7 VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_TOOLCHAIN_FILE "./../../vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

add_subdirectory(day7lib)
add_subdirectory(day7client)