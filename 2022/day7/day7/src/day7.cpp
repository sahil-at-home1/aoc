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
        for (auto item : curDir->get_child_dirs()) {
            total_size += find_dir_size(item.second);
        }
    }
    curDir->size = total_size;
    return curDir->size;
}

MyFileSystem *day7::gen_filesystem(const std::string inputFile) {
    MyFileSystem *fs = new MyFileSystem();
    std::string   line;
    std::ifstream f;

    f.open(inputFile);
    if (!f.is_open()) {
        std::cout << "could not open file: " << inputFile << std::endl;
        throw std::exception();
    }

    // always start with the root dir?
    MyDir *rootDir = new MyDir("/", nullptr);
    // pointer to mem that holds pointer to cur dir
    MyDir **curDir = new MyDir *;
    *curDir = rootDir;

    // read file line by line
    while (getline(f, line)) {
        // std::cout << line << std::endl;
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
                handle_cd(dir, curDir);
            } else if (cmd != "ls") {
                std::cout << "invalid command" << std::endl;
                throw std::exception();
            }
        } else {
            // handle results of ls command
            if (words[0] == "dir") {
                handle_ls_dir(words[1], curDir);
            } else {
                handle_ls_file(stoi(words[0]), words[1], curDir);
            }
        }
    }
    f.close();
    return rootDir;
    find_dir_size(&rootDir);
    return rootDir;
}

// Problem 1: find all dirs with size <= a big size and add their sizes
int day7::get_sum_of_small_dirs(MyDir *rootDir) {
    const int BIG_SIZE = 100000;
    MyDir    *curDir = rootDir;
    int       sumSizeOfSmallDirs = 0;

    // iterate through dirs
    std::vector<MyDir *> stack = std::vector<MyDir *>();
    stack.push_back(rootDir);
    while (!stack.empty()) {
        curDir = stack.back();
        stack.pop_back();
        // check dir size
        if (curDir->size <= BIG_SIZE) {
            sumSizeOfSmallDirs += curDir->size;
        }
        // add to stack of dirs to explore
        for (auto &item : curDir->get_child_dirs()) {
            MyDir *childDir = item.second;
            stack.push_back(childDir);
        }
    }

    return sumSizeOfSmallDirs;
}