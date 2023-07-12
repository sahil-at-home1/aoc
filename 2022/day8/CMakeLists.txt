add_subdirectory(day8lib)

add_executable(day8 main.cpp)

target_link_libraries(day8 day8lib)