#include "mydir.h"
#include "string.h"
#include <unordered_map>

day7::MyDir::MyDir(std::string name, MyDir *parent) {
    this->parent = parent;
    this->name = name;
    if (parent == nullptr) {
        this->path = name;
        this->depth = 0;
    } else if (parent->path == "/") {
        this->path = parent->path + name;
        this->depth = parent->depth + 1;
    } else {
        this->path = parent->path + "/" + name;
        this->depth = parent->depth + 1;
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

std::ostream &day7::operator<<(std::ostream &out, day7::MyDir &dir) {
    // print number of indents corresponding to depth
    for (int i = 0; i < dir.depth; i++) {
        out << "  ";
    }
    out << "- " << dir.path << ", " << dir.size << std::endl;

    // print subdirs
    for (auto &item : dir.get_child_dirs()) {
        day7::MyDir *subdir = item.second;
        out << *subdir;
    }

    // print files
    for (day7::MyFile *file : dir.files) {
        // print number of indents corresponding to depth
        for (int i = 0; i < dir.depth + 1; i++) {
            out << "  ";
        }
        out << "- " << *file;
    }

    return out;
}