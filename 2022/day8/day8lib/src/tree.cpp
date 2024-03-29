#include "tree.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

day8::Tree::Tree(int height) {
    this->height = height;
    for (auto &sightline : day8::SightlineValues) {
        this->visibility[sightline] = false;
        this->scenicFactor[sightline] = 0;
        this->scenicScore = 1;
    }
}

// a Tree is visible if it is visible from at least one sightline
bool day8::Tree::is_visible() {
    for (auto &sightline : day8::SightlineValues) {
        if (this->visibility[sightline] == true) {
            return true;
        }
    }
    return false;
}

int day8::Tree::get_scenic_score() {
    for (auto &sightline : day8::SightlineValues) {
        this->scenicScore = this->scenicScore * this->scenicFactor[sightline];
    }
    return this->scenicScore;
}

std::ostream &day8::operator<<(std::ostream &out, day8::Tree &tree) {
    out << "(" << tree.height << ":";
    out << (tree.is_visible() ? "Y" : "N");
    out << "[" << tree.scenicScore << "]";
    out << ")";
    return out;
}