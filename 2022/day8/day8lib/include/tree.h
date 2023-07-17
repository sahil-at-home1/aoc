#pragma once
#include "sightline.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace day8 {

class Tree {
  public:
    int                                       height;
    std::unordered_map<day8::Sightline, bool> visibility;

  public:
    Tree(int height);
    ~Tree();
    bool is_visible();

    friend std::ostream &operator<<(std::ostream &out, Tree &tree);
};
} // namespace day8