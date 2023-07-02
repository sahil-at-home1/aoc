#pragma once
#include "myfile.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class MyDir {
  public:
    int                   size;
    std::vector<MyFile *> files;
    std::vector<MyDir *>  dirs;
    std::string           path;
    MyDir                *parent;

  public:
    MyDir(std::string name, MyDir *parent);
    void                 add_dir(MyDir *dir) { this->dirs.push_back(dir); }
    void                 add_file(MyFile *file) { this->files.push_back(file); }
    friend std::ostream &operator<<(std::ostream &out, const MyDir &dir);
};
