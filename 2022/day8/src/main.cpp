// #include "day8lib.h"
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

enum class Sightline {
    RightToLeft,
    LeftToRight,
    TopToBot,
    BotToTop,
};
const std::vector<Sightline> SightlineValues = {
    Sightline::RightToLeft, Sightline::LeftToRight, Sightline::TopToBot,
    Sightline::BotToTop};

class Tree {
  public:
    int                                 height;
    std::unordered_map<Sightline, bool> visibility;

  public:
    Tree(int height);
    ~Tree();
    bool                 is_visible();
    friend std::ostream &operator<<(std::ostream &out, Tree const &tree);
};

Tree::Tree(int height) {
    this->height = height;
    for (auto &sightline : SightlineValues) {
        this->visibility[sightline] = false;
    }
}

bool Tree::is_visible() {
    for (auto &sightline : SightlineValues) {
        if (this->visibility[sightline] == false) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, Tree &tree) {
    out << "(" << tree.height << ":";
    for (auto &sightline : SightlineValues) {
        out << (tree.visibility[sightline] ? "Y" : "N");
    }
    out << ")";
    return out;
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
        // get digits from line to create trees for this row
        std::vector<Tree *> forestRow = std::vector<Tree *>();
        for (auto &c : line) {
            char heightChar =
                c; // copy so pointer doesn't include rest of string
            int height = atoi(&heightChar);
            std::cout << c << " interpreted as " << height << std::endl;
            forestRow.push_back(new Tree(height));
        }
        // add row of trees to forest grid
        forest.push_back(forestRow);
    }
    f.close();

    // traverse forest to determine tree visibility
    // check partial visibility along sightlines for each direction
    for (auto &sightline : {Sightline::LeftToRight, Sightline::RightToLeft}) {
        int hStart = 0;
        int hEnd = 0;
        int hIncrement = 1;
        int vStart = 0;
        int vEnd = 0;
        int vIncrement = 1;
        if (sightline == Sightline::LeftToRight) {
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
        int maxHeight = 0;
        for (int row = hStart; row != hEnd; row += hIncrement) {
            for (int col = vStart; col != vEnd; col += vIncrement) {
                Tree *tree = forest[row][col];
                // check if tree is on edge
                if ((sightline == Sightline::LeftToRight && col == vStart) ||
                    (sightline == Sightline::RightToLeft && col == vEnd)) {
                    tree->visibility[sightline] = true;
                    continue;
                }
                // check if tree is taller than all other trees along
                if (tree->height > maxHeight) {
                    tree->visibility[sightline] = true;
                    maxHeight = tree->height;
                }
            }
        }
    }

    // check vertical sightlines because inner/outer loop swapped
    for (auto &sightline : {Sightline::TopToBot, Sightline::BotToTop}) {
        int hStart = 0;
        int hEnd = 0;
        int hIncrement = 1;
        int vStart = 0;
        int vEnd = 0;
        int vIncrement = 1;
        if (sightline == Sightline::TopToBot) {
            vStart = 0;
            vEnd = forest.size();
            vIncrement = 1;
        } else {
            vStart = forest.size();
            vEnd = -1;
            vIncrement = -1;
        }
        int maxHeight = 0;
        for (int col = vStart; col != vEnd; col += vIncrement) {
            for (int row = hStart; row != hEnd; row += hIncrement) {
                Tree *tree = forest[row][col];
                // check if tree is on edge
                if ((sightline == Sightline::LeftToRight && row == hStart) ||
                    (sightline == Sightline::RightToLeft && row == hEnd)) {
                    tree->visibility[sightline] = true;
                    continue;
                }
                // check if tree is taller than all other trees along sightline
                if (tree->height > maxHeight) {
                    tree->visibility[sightline] = true;
                    maxHeight = tree->height;
                }
            }
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

    for (auto &row : forest) {
        for (auto &tree : row) {
            std::cout << *tree << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "There are " << visibleCount << " visible trees" << std::endl;
}
