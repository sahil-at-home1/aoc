#include "day7.h"
#include "gtest/gtest.h"

using namespace std;

const string testFile = "c:/users/sahil/dev/aoc/2022/day7/ez_input.txt";

TEST(Day7Test, FindDirSizes) {
    unordered_map<string, int> WANT = {
        {"/", 48381165}, {"/a", 94853}, {"/d", 24933642}, {"/a/e", 584}};

    day7::MyFileSystem *fs = day7::gen_filesystem(testFile);

    // iterate through dirs
    day7::MyDir *dir = fs->DFSNextDir(); // guaranteed to have root
    do {
        // assert dir size
        day7::set_dir_size(dir);
        ASSERT_EQ(dir->size, WANT[dir->path])
            << "Dir " << dir->path << " has size " << dir->size
            << ", but expected " << WANT[dir->path];
        // iterate
        dir = fs->DFSNextDir();
    } while (dir != nullptr);
    fs->DFSReset();
}

TEST(Day7Test, GetSumOfSmallDirs) {
    day7::MyFileSystem *fs = day7::gen_filesystem(testFile);

    int sumOfSmallDirs = day7::get_sum_of_small_dirs(fs);

    ASSERT_EQ(sumOfSmallDirs, 95437);
}