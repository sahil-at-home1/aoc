#include "day8lib.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

// const std::string inputFile =
// "/home/sahil/dev/aoc/2022/day8/input/small.txt";
const std::string inputFile =
    "C:/users/sahil/dev/aoc/2022/day8/input/small.txt";

int main() {
    // read input
    std::string   line;
    std::ifstream f;

    f.open(inputFile);
    if (!f.is_open()) {
        std::cout << "could not open file: " << inputFile << std::endl;
        throw std::exception();
    }

    // create forest of trees by reading file
    std::vector<std::vector<day8::Tree *>> forest;
    while (getline(f, line)) {
        // get digits from line to create trees for this row
        std::vector<day8::Tree *> forestRow = std::vector<day8::Tree *>();
        for (auto &c : line) {
            char heightChar = c; // copy so ptr doesn't include rest of string
            int  height = atoi(&heightChar);
            forestRow.push_back(new day8::Tree(height));
        }
        // add row of trees to forest grid
        forest.push_back(forestRow);
    }
    f.close();

    // check vertical sightlines because inner/outer loop swapped
    for (auto &sightline : day8::SightlineValues) {
        switch (sightline) {
        case day8::Sightline::LeftToRight:
            day8::check_left_to_right(&forest, forest.size());
            break;
        case day8::Sightline::RightToLeft:
            day8::check_right_to_left(&forest, forest.size());
            break;
        case day8::Sightline::TopToBot:
            day8::check_top_to_bot(&forest, forest.size());
            break;
        case day8::Sightline::BotToTop:
            day8::check_bot_to_top(&forest, forest.size());
            break;
        }
    }

    // check visibility of each tree
    int visibleCount = 0;
    for (int row = 0; row < forest.size(); row++) {
        for (int col = 0; col < forest.size(); col++) {
            if (forest[row][col]->is_visible()) {
                visibleCount += 1;
            }
        }
    }

    for (auto &sightline : day8::SightlineValues) {
        std::cout << "Checking sightline: " << sightline << std::endl;
        for (auto &row : forest) {
            for (auto &tree : row) {
                std::string vis = tree->visibility[sightline] ? "Y" : "N";
                std::cout << "(" << tree->height << ":" << vis << ") ";
            }
            std::cout << std::endl;
        }
    }
    std::cout << "There are " << visibleCount << " visible trees" << std::endl;
}
