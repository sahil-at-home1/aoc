cmake_minimum_required(VERSION 3.21.0)
project(Day7Lib VERSION 0.1.0 LANGUAGES C CXX)

add_library(Day7Lib 
    src/myfile.cpp 
    src/mydir.cpp 
    src/myfilesystem.cpp 
    src/day7.cpp
    )

target_include_directories(Day7Lib PUBLIC ./include)