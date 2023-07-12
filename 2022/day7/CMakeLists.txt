enable_testing()

find_package(GTest CONFIG REQUIRED)

add_subdirectory(day7lib)

add_executable(day7main main.cpp)
add_executable(day7test test.cpp)

target_link_libraries(day7test PUBLIC day7lib GTest::gtest GTest::gtest_main)
target_link_libraries(day7main PUBLIC day7lib)

include(GoogleTest)
# gtest_discover_tests(day7test)

