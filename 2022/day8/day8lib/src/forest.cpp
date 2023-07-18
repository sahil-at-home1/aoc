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

    // get the n in n x n grid
    f.open(inputFile);
    if (!f.is_open()) {
        std::cout << "could not open file: " << inputFile << std::endl;
        throw std::exception();
    }
    int n = 0;
    while (getline(f, line)) {
        n += 1;
    }
    f.close();
    this->n = n;
    this->trees =
        std::vector<std::vector<day8::Tree *>>(n, std::vector<day8::Tree *>(n));

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

std::ostream &day8::operator<<(std::ostream &out, day8::Forest &forest) {
    for (auto &sightline : day8::SightlineValues) {
        out << "Checking sightline: " << sightline << std::endl;
        for (int row = 0; row < forest.n; row++) {
            for (int col = 0; col < forest.n; col++) {
                day8::Tree *tree = forest.get_tree(row, col);
                std::string vis = tree->visibility[sightline] ? "Y" : "N";
                out << "(" << tree->height << ":" << vis << ") ";
            }
            out << std::endl;
        }
    }
    return out;
}