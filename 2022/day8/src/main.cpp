// clang-format off
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> // order matters
// clang-format on
#include "day8lib.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

const std::string inputFile = "C:/users/sahil/dev/aoc/2022/day8/input/large.txt";

int main() {
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);

    day8::Forest *forest = new day8::Forest(inputFile);
    day8::check_tree_visibilities(forest);

    // problem 1
    std::cout << "There are " << forest->get_num_trees_visible() << " visible trees" << std::endl;
    // problem 2
    std::cout << "The max scenic factor is " << forest->get_max_scenic_score() << std::endl;

    delete forest;

    _CrtDumpMemoryLeaks();
}
