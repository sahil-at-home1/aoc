#include "day8lib.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <vector>

const std::string inputFile = "/home/sahil/dev/aoc/2022/day8/input/small.txt";

enum class Sightline {
    RightToLeft,
    LeftToRight,
    TopToBot,
    BotToTop,
};
const std::vector<Sightline> SightlineValues = {Sightline::RightToLeft,
                                                Sightline::LeftToRight,
                                                Sightline::TopToBot,
                                                Sightline::BotToTop}

class Tree {
  public:
    int                                 height;
    std::unordered_map<Sightline, bool> visibility;

  public:
    Tree(int height);
    ~Tree();
    bool is_visible();
};

Tree::Tree(int height) {
    this->height = height;
    for (auto &sightline : SightlineValues) {
        this->visibility[sightline] = false;
    }
}

Tree::is_visible() {
    for (auto &sightline : SightlineValues) {
        if (this->visibility[sightline] == false) {
            return false;
        }
    }
    return true;
}

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
    std::vector<std::vector<Tree *>> forest;
    while (getline(f, line)) {
        // split line by spaces
        const std::string        delim = " ";
        std::vector<std::string> words;
        size_t                   end = line.find(delim);
        while (end != std::string::npos) {
            words.push_back(line.substr(0, end));
            line = line.substr(end + delim.length(), line.length());
            end = line.find(delim);
        }
        words.push_back(line);
        // create trees for this row
        std::vector<Tree *> forestRow = std::vector<Tree *>();
        for (auto &height : words) {
            forestRow.push_back(new Tree(stoi(height)));
        }
        // add row to forest grid
        forest.push_back(forestRow);
    }
    f.close();

    // traverse forest to determine tree visibility
    for (auto &direction : [ "left", "right" ]) {
        int hStart = 0;
        int hEnd = 0;
        int hIncrement = 1;
        int vStart = 0;
        int vEnd = 0;
        int vIncrement = 1;
        if (direction == "left") {
            // check visibility from left to right
            hStart = 0;
            hEnd = forest.size();
            hIncrement = 1;
        } else {
            // check visibility from right to left;
            hStart = forest.size();
            hEnd = -1;
            hIncrement = -1;
        }
    }

    for (auto &direction : [ "top", "bot" ]) {
        int hStart = 0;
        int hEnd = 0;
        int vStart = 0;
        int vEnd = 0;
        int vIncrement = 1;
        if (direction == "top") {
            vStart = 0;
            vEnd = forest.size();
            vIncrement = 1;
        } else {
            vStart = forest.size();
            vEnd = -1;
            vIncrement = -1;
        }
        for (int col = vStart; col < vEnd; col += vIncrement) {
            for (int row = hStart; row < hEnd; row += hIncrement) {
                Tree *tree = forest[row][col];
                if (row == 0) {
                    tree->visible = true;
                } else {
                    // check trees between it and edge of grid on 4 sides
                }
            }
        }
    }
}
