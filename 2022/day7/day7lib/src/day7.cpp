#include "day7.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

int day7::set_dir_size(day7::MyDir *curDir) {
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
        for (auto &item : curDir->get_child_dirs()) {
            MyDir *dir = item.second;
            total_size += day7::set_dir_size(dir);
        }
    }
    curDir->size = total_size;
    return curDir->size;
}

day7::MyFileSystem *day7::gen_filesystem(const std::string inputFile) {
    day7::MyFileSystem *fs = new day7::MyFileSystem();
    std::string         line;
    std::ifstream       f;

    f.open(inputFile);
    if (!f.is_open()) {
        std::cout << "could not open file: " << inputFile << std::endl;
        throw std::exception();
    }

    // read file line by line
    while (getline(f, line)) {
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
                // set current dir in file system
                std::string dir = words[2];
                fs->setCurDir(dir);
            } else if (cmd != "ls") {
                std::cout << "invalid command" << std::endl;
                throw std::exception();
            }
        } else {
            // handle results of ls command
            if (words[0] == "dir") {
                // add new dir to cur dir
                fs->mkdir(words[1]);
            } else {
                // add new file to cur dir
                fs->touch(words[1], std::stoi(words[0]));
            }
        }
    }
    f.close();
    set_dir_size(fs->getRootDir());
    return fs;
}

// Problem 1: find all dirs with size <= a big size and add their sizes
int day7::get_sum_of_small_dirs(day7::MyFileSystem *fs) {
    const int BIG_SIZE = 100000;
    int       sumSizeOfSmallDirs = 0;

    // iterate through dirs
    day7::MyDir *dir = fs->DFSNextDir(); // guaranteed to have root
    do {
        // check dir size
        if (dir->size <= BIG_SIZE) {
            sumSizeOfSmallDirs += dir->size;
        }
        // iterate
        dir = fs->DFSNextDir();
    } while (dir != nullptr);
    fs->DFSReset();

    return sumSizeOfSmallDirs;
}