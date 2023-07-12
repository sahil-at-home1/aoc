#pragma once
#include "myfile.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace day7 {

class MyDir {
  public:
    int                   size;
    std::vector<MyFile *> files;
    std::string           name;
    std::string           path;
    MyDir                *parent;
    int                   depth;

  private:
    std::unordered_map<std::string, MyDir *> dirs;

  public:
    MyDir(std::string name, MyDir *parent);
    std::unordered_map<std::string, MyDir *> get_child_dirs();
    void                                     add_child_dir(MyDir *dir);
    MyDir                                   *get_child_dir(std::string);
    void                                     add_child_file(MyFile *file);
    friend std::ostream &operator<<(std::ostream &out, MyDir &dir);
};
} // namespace day7