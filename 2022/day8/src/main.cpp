#include "day8lib.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <vector>

const std::string inputFile = "/home/sahil/dev/aoc/2022/day8/input/small.txt";

class Tree {
  public:
    int  height;
    bool visible;
    Tree(int height);
    ~Tree();
};

Tree::Tree(int height) {
    this->height = height;
    this->visible = true; // default
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
    for (int i = 0; i < forest.size(); i++) {
        for (int j = 0; j < forest[i].size(); j++) {
            Tree *tree = forest[i][j];
            if (i == 0 || j == 0) {
                // trees on edges of forest are visible
                tree->visible = true;
            } else {
                // check trees between it and edge of grid on 4 sides
            }
        }
    }
}
