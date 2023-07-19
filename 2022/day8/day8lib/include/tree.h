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
  private:
    int scenicScore;

  public:
    int                                       height;
    std::unordered_map<day8::Sightline, bool> visibility;
    std::unordered_map<day8::Sightline, int>  scenicFactor;

  public:
    Tree(int height);
    bool is_visible();
    int  get_scenic_score();

    friend std::ostream &operator<<(std::ostream &out, Tree &tree);
};
} // namespace day8