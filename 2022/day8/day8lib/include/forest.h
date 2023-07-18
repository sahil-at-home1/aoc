#pragma once
#include "tree.h"
#include <iostream>
#include <vector>

namespace day8 {

class Forest {
  private:
    std::vector<std::vector<day8::Tree *>> trees;

  public:
    int n;

  public:
    Forest(std::string inputFile);
    ~Forest();
    day8::Tree          *get_tree(int row, int col);
    int                  get_num_trees_visible();
    friend std::ostream &operator<<(std::ostream &out, day8::Forest &forest);
};

} // namespace day8