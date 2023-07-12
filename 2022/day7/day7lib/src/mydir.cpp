#include "mydir.h"
#include "string.h"
#include <unordered_map>

day7::MyDir::MyDir(std::string name, MyDir *parent) {
    this->parent = parent;
    this->name = name;
    if (parent == nullptr) {
        this->path = name;
    } else if (parent->path == "/") {
        this->path = parent->path + name;
    } else {
        this->path = parent->path + "/" + name;
    }
    this->size = 0;
}

void day7::MyDir::add_child_file(day7::MyFile *file) {
    this->files.push_back(file);
}

void day7::MyDir::add_child_dir(day7::MyDir *dir) {
    this->dirs[dir->name] = dir;
}

std::unordered_map<std::string, day7::MyDir *> day7::MyDir::get_child_dirs() {
    return this->dirs;
}

day7::MyDir *day7::MyDir::get_child_dir(std::string name) {
    auto dir = this->dirs.find(name);
    if (dir == this->dirs.end()) {
        return nullptr;
    }
    return dir->second;
}

std::ostream &operator<<(std::ostream &out, day7::MyDir &dir) {
    std::string parentPath = "N/A";
    if (dir.parent) {
        parentPath = dir.parent->path;
    }
    out << "MyDir(" << dir.name << ", " << dir.path << ", "
        << "parent: " << parentPath << ", " << dir.size << ", (" << std::endl;
    for (day7::MyFile *file : dir.files) {
        out << " - " << *file;
    }
    for (auto &item : dir.get_child_dirs()) {
        day7::MyDir *subdir = item.second;
        out << " - MyDir(" << subdir->name << ", " << subdir->size << ")"
            << std::endl;
    }
    out << " )" << std::endl;
    out << ")" << std::endl;
    return out;
}