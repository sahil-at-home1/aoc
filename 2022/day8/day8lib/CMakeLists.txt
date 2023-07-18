add_library(day8lib STATIC src/sightline.cpp src/tree.cpp src/forest.cpp src/day8lib.cpp)

target_include_directories(day8lib PUBLIC ./include)