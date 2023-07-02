#include "mydir.h"
#include "string.h"

MyDir::MyDir(std::string name, MyDir *parent) {
    this->parent = parent;
    if (parent == nullptr) {
        this->path = name;
    } else if (parent->path == "/") {
        this->path = parent->path + name;
    } else {
        this->path = parent->path + "/" + name;
        this->size = 0;
    }
}

std::ostream &operator<<(std::ostream &out, const MyDir &dir) {
    std::string parentPath = "N/A";
    if (dir.parent) {
        parentPath = dir.parent->path;
    }
    out << "MyDir(" << dir.path << ", "
        << "parent: " << parentPath << ", " << dir.size << ", (" << std::endl;
    for (MyFile *file : dir.files) {
        out << " - " << *file;
    }
    for (MyDir *subdir : dir.dirs) {
        out << " - MyDir(" << subdir->path << ", " << subdir->size << ")"
            << std::endl;
    }
    out << " )" << std::endl;
    out << ")" << std::endl;
    return out;
}