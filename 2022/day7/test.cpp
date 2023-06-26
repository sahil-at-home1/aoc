#include "day7.h"
#include "gtest/gtest.h"

using namespace std;

const string testFile = "c:/users/sahil/dev/aoc/2022/day7/ez_input.txt";

TEST(Day7Test, TestFindDirSize) {
    unordered_map<string, int> WANT = {
        {"/", 48381165}, {"a", 94853}, {"d", 24933642}, {"e", 584}};
    DirMap *dirs = new DirMap();

    gen_dir_map(testFile, dirs);

    for (auto &item : *dirs) {
        MyDir *dir = item.second;
        ASSERT_EQ(dir->size, WANT[dir->name]);
    }
}

TEST(Day7Test, TestSumOfSmallDirs) {
    DirMap *dirs = new DirMap();
    read_filesystem(testFile, dirs);
    int sumOfSmallDirs = get_sum_of_small_dirs(dirs);
    ASSERT_EQ(sumOfSmallDirs, 95437);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
