#include "day7.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

using namespace day7;

int day7::find_dir_size(MyDir *curDir) {
    if (curDir == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
    // add size of files in the directory
    int total_size = 0;
    if (curDir->files.size() > 0) {
        for (MyFile *file : curDir->files) {
            total_size += file->size;
        }
    }
    // recursively find size of subdirectories
    if (curDir->files.size() > 0) {
        for (MyDir *dir : curDir->dirs) {
            total_size += find_dir_size(dir);
        }
    }
    curDir->size = total_size;
    return curDir->size;
}

void handle_ls_dir(const std::string name, DirMap *dirs, MyDir **curDir) {
    if ((*curDir) == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
    MyDir *subdir = nullptr;
    // create new directory if never seen before
    if (dirs->find(name) == dirs->end()) {
        subdir = new MyDir(name, (*curDir));
        dirs->insert(make_pair(name, subdir));
    } else {
        subdir = (*dirs)[name];
    }
    (*curDir)->add_dir(subdir);
}

void handle_ls_file(const int size, const std::string name, MyDir **curDir) {
    if ((*curDir) == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
    (*curDir)->add_file(new MyFile(name, size));
}

void handle_cd(const std::string dir, DirMap *dirs, MyDir **curDir) {
    if ((*curDir) == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
    if (dir == "..") {
        if ((*curDir)->parent == nullptr) {
            std::cout << "the current directory, " << (*curDir)->name
                      << ", has null parent" << std::endl;
            throw std::exception();
        }
        (*curDir) = (*curDir)->parent;

    } else {
        // create new directory if never seen before
        if (dirs->find(dir) == dirs->end()) {
            MyDir *new_dir = new MyDir(dir, (*curDir));
            (*curDir)->add_dir(new_dir);
            dirs->insert(make_pair(dir, new_dir));
        }
        // switch to specified directory
        std::cout << "switching to directory " << dir << ", and found "
                  << (*dirs)[dir]->name << std::endl;
        (*curDir) = (*dirs)[dir];
    }
    if ((*curDir) == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
}

// generates all directory objects, but does NOT calculate their sizes
void day7::gen_dir_map(const std::string input_file, DirMap *dirs) {
    std::string   line;
    std::ifstream f;

    f.open(input_file);
    if (!f.is_open()) {
        std::cout << "could not open file" << std::endl;
        throw std::exception();
    }

    // always start with the root dir?
    (*dirs)["/"] = new MyDir("/", nullptr);
    // pointer to mem that holds pointer to cur dir
    MyDir **curDir = new MyDir *;
    *curDir = (*dirs)["/"];

    // read file line by line
    while (getline(f, line)) {
        std::cout << "Handling line: " << line << std::endl;
        std::cout << "Current Directory: " << (*curDir)->name << std::endl;
        std::cout << *curDir << std::endl;
        // split line by spaces
        const std::string        delim = " ";
        std::vector<std::string> words;
        size_t                   end = line.find(delim);
        while (end != std::string::npos) {
            words.push_back(line.substr(0, end));
            line = line.substr(end + delim.length(), line.length());
            end = line.find(delim);
        }
        words.push_back(line);

        // check what command was given
        if (words[0] == "$") {
            std::string cmd = words[1];
            if (cmd == "cd") {
                std::string dir = words[2];
                handle_cd(dir, dirs, curDir);
                std::cout << "current directory is " << (*curDir)->name
                          << std::endl;
            } else if (cmd != "ls") {
                std::cout << "invalid command" << std::endl;
                throw std::exception();
            }
        } else {
            // handle results of ls command
            if (words[0] == "dir") {
                handle_ls_dir(words[1], dirs, curDir);
            } else {
                handle_ls_file(stoi(words[0]), words[1], curDir);
            }
        }
    }
    f.close();
}

void day7::read_filesystem(const std::string inputFile, DirMap *dirs) {
    gen_dir_map(inputFile, dirs);
    find_dir_size((*dirs)["/"]);
}

// Problem 1: find all dirs with size <= a big size and add their sizes
int day7::get_sum_of_small_dirs(DirMap *dirs) {
    int       sumSizeOfSmallDirs = 0;
    const int BIG_SIZE = 100000;
    for (auto item : (*dirs)) {
        std::string dirName = item.first;
        MyDir      *dir = item.second;
        if (dir->size <= BIG_SIZE) {
            sumSizeOfSmallDirs += dir->size;
        }
    }
    std::cout << "sum of small dir sizes is: " << sumSizeOfSmallDirs
              << std::endl;
    return 0;
}