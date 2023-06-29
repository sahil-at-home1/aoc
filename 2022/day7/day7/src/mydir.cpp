#include "mydir.h"
#include "string.h"

MyDir::MyDir(std::string name, MyDir *parent) {
    this->parent = parent;
    this->name = name;
    this->size = 0;
}

std::ostream &operator<<(std::ostream &out, const MyDir &dir) {
    std::string parent_name = "N/A";
    if (dir.parent) {
        parent_name = dir.parent->name;
    }
    out << "MyDir(" << dir.name << ", "
        << "parent: " << parent_name << ", " << dir.size << ", (" << std::endl;
    for (MyFile *file : dir.files) {
        out << " - " << *file;
    }
    for (MyDir *subdir : dir.dirs) {
        out << " - MyDir(" << subdir->name << ", " << subdir->size << ")"
            << std::endl;
    }
    out << " )" << std::endl;
    out << ")" << std::endl;
    return out;
}