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

void check_left_to_right(std::vector<std::vector<Tree *>> *forest, int n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int h = hStart; h != hEnd; h += hIncrement) {
        for (int v = vStart; v != vEnd; v += vIncrement) {
            Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (v == vStart) {
                tree->visibility[Sightline::LeftToRight] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[Sightline::LeftToRight] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void check_right_to_left(std::vector<std::vector<Tree *>> *forest, int n) {
    int hStart = n - 1;
    int hEnd = -1;
    int hIncrement = -1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int h = hStart; h != hEnd; h += hIncrement) {
        for (int v = vStart; v != vEnd; v += vIncrement) {
            Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (v == vStart) {
                tree->visibility[Sightline::RightToLeft] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[Sightline::RightToLeft] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void check_top_to_bot(std::vector<std::vector<Tree *>> *forest, int n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vIncrement) {
        for (int h = hStart; h != hEnd; h += hIncrement) {
            Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (h == hStart) {
                tree->visibility[Sightline::TopToBot] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[Sightline::TopToBot] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void check_bot_to_top(std::vector<std::vector<Tree *>> *forest, int n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = n - 1;
    int vEnd = -1;
    int vIncrement = -1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vIncrement) {
        for (int h = hStart; h != hEnd; h += hIncrement) {
            Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (h == hStart) {
                tree->visibility[Sightline::TopToBot] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[Sightline::TopToBot] = true;
                maxHeight = tree->height;
            }
        }
    }
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

    // check vertical sightlines because inner/outer loop swapped
    for (auto &sightline : SightlineValues) {
        switch (sightline) {
        case Sightline::LeftToRight:
            check_left_to_right(&forest, forest.size());
            break;
        case Sightline::RightToLeft:
            check_right_to_left(&forest, forest.size());
            break;
        case Sightline::TopToBot:
            check_top_to_bot(&forest, forest.size());
            break;
        case Sightline::BotToTop:
            check_bot_to_top(&forest, forest.size());
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

    for (auto &row : forest) {
        for (auto &tree : row) {
            std::cout << *tree << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "There are " << visibleCount << " visible trees" << std::endl;
}
