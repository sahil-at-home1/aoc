#include "day7.h"
#include "gtest/gtest.h"

using namespace std;

const string testFile = "c:/users/sahil/dev/aoc/2022/day7/ez_input.txt";

TEST(Day7Test, FindDirSizes) {
    unordered_map<string, int> WANT = {
        {"/", 48381165}, {"/a", 94853}, {"/d", 24933642}, {"/a/e", 584}};

    MyDir *rootDir = day7::gen_dirs(testFile);

    // iterate through dirs
    std::vector<MyDir *> stack = std::vector<MyDir *>();
    stack.push_back(rootDir);
    MyDir **curDir = new MyDir *;
    (*curDir) = rootDir;
    while (!stack.empty()) {
        (*curDir) = stack.back();
        stack.pop_back();
        // assert dir size
        day7::find_dir_size(curDir);
        ASSERT_EQ((*curDir)->size, WANT[(*curDir)->path])
            << "Dir " << (*curDir)->path << " has size " << (*curDir)->size
            << ", but expected " << WANT[(*curDir)->path];
        // add to stack of dirs to explore
        for (auto &item : (*curDir)->get_child_dirs()) {
            MyDir *childDir = item.second;
            stack.push_back(childDir);
        }
    }
    delete curDir;
}

TEST(Day7Test, GetSumOfSmallDirs) {
    MyDir *rootDir = day7::read_filesystem(testFile);
    int    sumOfSmallDirs = day7::get_sum_of_small_dirs(rootDir);
    ASSERT_EQ(sumOfSmallDirs, 95437);
}