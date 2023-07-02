#include "mydir.h"
#include "string.h"
#include <unordered_map>

MyDir::MyDir(std::string name, MyDir *parent) {
    this->parent = parent;
    this->name = name;
    if (parent == nullptr) {
        this->path = name;
    } else if (parent->path == "/") {
        this->path = parent->path + name;
    } else {
        this->path = parent->path + "/" + name;
        this->size = 0;
    }
}

void MyDir::add_child_file(MyFile *file) { this->files.push_back(file); }

void MyDir::add_child_dir(MyDir *dir) { this->dirs[dir->path] = dir; }

std::unordered_map<std::string, MyDir *> MyDir::get_child_dirs() {
    return this->dirs;
}

MyDir *MyDir::get_child_dir(std::string name) {
    auto dir = this->dirs.find(name);
    if (dir == this->dirs.end()) {
        return nullptr;
    }
    return dir->second;
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
    for (auto item : dir.dirs) {
        MyDir *subdir = item.second;
        out << " - MyDir(" << subdir->path << ", " << subdir->size << ")"
            << std::endl;
    }
    out << " )" << std::endl;
    out << ")" << std::endl;
    return out;
}