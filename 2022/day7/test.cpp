#include "day7.h"
#include "gtest/gtest.h"

using namespace std;

const string testFile = "c:/users/sahil/dev/aoc/2022/day7/ez_input.txt";
// const string testFile = "/home/sahil/dev/aoc/2022/day7/ez_input.txt";

TEST(day7test, FindDirSizes) {
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

// part 1 test
TEST(day7test, GetSumOfSmallDirs) {
    day7::MyFileSystem *fs = day7::gen_filesystem(testFile);

    int sumOfSmallDirs = day7::get_sum_of_small_dirs(fs);

    cout << *fs << std::endl;

    ASSERT_EQ(sumOfSmallDirs, 95437);
}

// part 2 test
TEST(day7test, FreeSpace) {
    day7::MyFileSystem *fs = day7::gen_filesystem(testFile);

    int sizeOfDirToDelete = day7::get_size_of_smallest_dir_to_free_space(fs);

    cout << *fs << std::endl;

    ASSERT_EQ(sizeOfDirToDelete, 24933642);
}