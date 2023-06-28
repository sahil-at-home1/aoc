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
    std::string           name;
    MyDir                *parent;

  public:
    MyDir(std::string name, MyDir *parent) {
        this->parent = parent;
        this->name = name;
        this->size = 0;
    }
    void                 add_dir(MyDir *dir) { this->dirs.push_back(dir); }
    void                 add_file(MyFile *file) { this->files.push_back(file); }
    friend std::ostream &operator<<(std::ostream &out, const MyDir &dir) {
        std::string parent_name = "N/A";
        if (dir.parent) {
            parent_name = dir.parent->name;
        }
        out << "MyDir(" << dir.name << ", "
            << "parent: " << parent_name << ", " << dir.size << ", (";
        for (MyFile *file : dir.files) {
            out << *file << ", ";
        }
        out << "), ";
        for (MyDir *subdir : dir.dirs) {
            out << "MyDir(" << subdir->name << ", " << subdir->size << "), ";
        }
        out << ")";
        return out;
    }
};
