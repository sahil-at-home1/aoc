#include "forest.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

// initializes a nxn grid forest of pointers to trees
// ALSO initializes the trees pointed to
day8::Forest::Forest(std::string inputFile) {
    std::string   line;
    std::ifstream f;

    // open file
    f.open(inputFile);
    if (!f.is_open()) {
        std::cout << "could not open file: " << inputFile << std::endl;
        throw std::exception();
    }

    // get the n in n x n grid
    int lines = 0;
    while (getline(f, line)) {
        lines += 1;
    }
    this->n = lines;
    this->trees =
        std::vector<std::vector<day8::Tree *>>(n, std::vector<day8::Tree *>(n));

    // reset file cursor to start of file
    f.clear();
    f.seekg(0);

    // fill in trees
    int row = 0;
    while (getline(f, line)) {
        // get digits from line to create trees for this row
        int col = 0;
        for (auto &c : line) {
            char heightChar = c; // copy so ptr doesn't include rest of string
            int  height = atoi(&heightChar);
            this->trees[row][col] = new day8::Tree(height);
            col += 1;
        }
        row += 1;
    }
    f.close();
}

day8::Forest::~Forest() {
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->n; col++) {
            delete this->trees[row][col];
        }
    }
}

day8::Tree *day8::Forest::get_tree(int row, int col) {
    return this->trees[row][col];
}

int day8::Forest::get_num_trees_visible() {
    int visibleCount = 0;
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->n; col++) {
            if (this->get_tree(row, col)->is_visible()) {
                visibleCount += 1;
            }
        }
    }
    return visibleCount;
}

int day8::Forest::get_max_scenic_score() {
    int maxScenicScore = 0;
    for (int row = 0; row < this->n; row++) {
        for (int col = 0; col < this->n; col++) {
            int scenicScore = this->get_tree(row, col)->get_scenic_score();
            if (scenicScore > maxScenicScore) {
                maxScenicScore = scenicScore;
            }
        }
    }
    return maxScenicScore;
}

std::ostream &day8::operator<<(std::ostream &out, day8::Forest &forest) {
    for (auto &sightline : day8::SightlineValues) {
        out << "Checking sightline: " << sightline << std::endl;
        for (int row = 0; row < forest.n; row++) {
            for (int col = 0; col < forest.n; col++) {
                day8::Tree *tree = forest.get_tree(row, col);
                std::string vis = tree->visibility[sightline] ? "Y" : "N";
                int         sf = tree->scenicFactor[sightline];
                out << "(" << tree->height << ":" << vis << "[" << sf << "]"
                    << ") ";
            }
            out << std::endl;
        }
    }
    return out;
}