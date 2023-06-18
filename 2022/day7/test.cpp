#include "day7.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Day7Test, TestEZInput) {
    string testFile = "ez_input.txt";
    int    sumOfSmallDirs = get_sum_of_small_dirs(testFile);
    ASSERT_EQ(sumOfSmallDirs, 95437);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
