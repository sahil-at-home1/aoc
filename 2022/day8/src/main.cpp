#define _CRTDBG_MAP_ALLOC

#include "day8lib.h"
#include <crtdbg.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

// const std::string inputFile =
// "/home/sahil/dev/aoc/2022/day8/input/small.txt";
const std::string inputFile =
    "C:/users/sahil/dev/aoc/2022/day8/input/small.txt";

int main() {
    day8::Forest *forest = new day8::Forest(inputFile);
    day8::check_tree_visibilities(forest);

    std::cout << *forest << std::endl;
    std::cout << "There are " << forest->get_num_trees_visible()
              << " visible trees" << std::endl;

    delete forest;

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}
