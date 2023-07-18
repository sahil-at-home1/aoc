#include "day8lib.h"
#include "gtest/gtest.h"

using namespace std;

const string testFile = "c:/users/sahil/dev/aoc/2022/day8/input/small.txt";

TEST(day8test, small) {
    day8::Forest *forest = new day8::Forest(testFile);
    day8::check_tree_visibilities(forest);
    ASSERT_EQ(forest->get_num_trees_visible(), 21);
    delete forest;
}