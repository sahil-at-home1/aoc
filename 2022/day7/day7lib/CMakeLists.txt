cmake_minimum_required(VERSION 3.21.0)
project(Day7Lib VERSION 0.1.0 LANGUAGES C CXX)

add_library(Day7Lib 
    day7/day7/src/myfile.cpp 
    day7/day7/src/mydir.cpp 
    day7/day7/src/myfilesystem.cpp 
    day7/day7/src/day7.cpp
    )

target_include_directories(Day7Lib PUBLIC day7/day7/include)

