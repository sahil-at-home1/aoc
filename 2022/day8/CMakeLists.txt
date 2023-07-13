enable_testing()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_subdirectory(day8lib)

add_executable(day8main main.cpp)
add_executable(day8test test.cpp)

target_link_libraries(day8main day8lib)
target_link_libraries(day8test day8lib GTest::gtest GTest::gtest_main)



