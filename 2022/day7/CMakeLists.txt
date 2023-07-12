# enable_testing()

# find_package(GTest CONFIG REQUIRED)

add_subdirectory(day7lib)

add_executable(day7main main.cpp)

# add_executable(Day7Main main.cpp)
# add_executable(Day7Test test.cpp)

# target_include_directories(day7main PUBLIC day7lib/include)
# target_include_directories(Day7Main PUBLIC day7lib/include)
# target_include_directories(Day7Test PUBLIC day7lib/include)

# target_link_libraries(Day7Test LINK_PUBLIC Day7Lib GTest::gtest GTest::gtest_main)
target_link_libraries(day7main PRIVATE day7lib)

# include(GoogleTest)
# gtest_discover_tests(Day7Test)

