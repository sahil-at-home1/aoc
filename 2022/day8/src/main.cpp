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

    // check vertical sightlines because inner/outer loop swapped
    for (auto &sightline : day8::SightlineValues) {
        switch (sightline) {
        case day8::Sightline::LeftToRight:
            day8::check_left_to_right(forest);
            break;
        case day8::Sightline::RightToLeft:
            day8::check_right_to_left(forest);
            break;
        case day8::Sightline::TopToBot:
            day8::check_top_to_bot(forest);
            break;
        case day8::Sightline::BotToTop:
            day8::check_bot_to_top(forest);
            break;
        }
    }

    std::cout << *forest << std::endl;

    std::cout << "There are " << forest->get_num_trees_visible()
              << " visible trees" << std::endl;

    delete forest;

    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
}
