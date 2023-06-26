#include "day7.h"
#include <stdexcept>
#include <string.h>

using namespace std;

int find_dir_size(MyDir *curDir) {
    if (curDir == nullptr) {
        cout << "current directory is null" << endl;
        throw exception();
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

void handle_ls_dir(const string name, DirMap *dirs, MyDir *curDir) {
    if (curDir == nullptr) {
        cout << "current directory is null" << endl;
        throw exception();
    }
    MyDir *subdir = nullptr;
    // create new directory if never seen before
    if (dirs->find(name) == dirs->end()) {
        subdir = new MyDir(name, curDir);
        dirs->insert(make_pair(name, subdir));
    } else {
        subdir = (*dirs)[name];
    }
    curDir->add_dir(subdir);
}

void handle_ls_file(const int size, const string name, MyDir *curDir) {
    if (curDir == nullptr) {
        cout << "current directory is null" << endl;
        throw exception();
    }
    curDir->add_file(new MyFile(name, size));
}

void handle_cd(const string dir, DirMap *dirs, MyDir *curDir) {
    if (curDir == nullptr) {
        cout << "current directory is null" << endl;
        throw exception();
    }
    if (dir == "..") {
        if (curDir->parent == nullptr) {
            cout << "current directory parent is null" << endl;
            throw exception();
        }
        curDir = curDir->parent;

    } else {
        // create new directory if never seen before
        if (dirs->find(dir) == dirs->end()) {
            MyDir *new_dir = new MyDir(dir, curDir);
            dirs->insert(make_pair(dir, new_dir));
        }
        // switch to specified directory
        curDir = (*dirs)[dir];
    }
    if (curDir == nullptr) {
        cout << "current directory is null" << endl;
        throw exception();
    }
}

// generates all directory objects, but does NOT calculate their sizes
void gen_dir_map(const string input_file, DirMap *dirs) {
    string   line;
    ifstream f;

    f.open(input_file);
    if (!f.is_open()) {
        cout << "could not open file" << endl;
        throw exception();
    }

    // always start with the root dir?
    (*dirs)["/"] = new MyDir("/", nullptr);
    MyDir *curDir = (*dirs)["/"];

    // read file line by line
    while (getline(f, line)) {
        // split line by spaces
        const string   delim = " ";
        vector<string> words;
        size_t         end = line.find(delim);
        while (end != string::npos) {
            words.push_back(line.substr(0, end));
            line = line.substr(end + delim.length(), line.length());
            end = line.find(delim);
        }
        words.push_back(line);

        // check what command was given
        if (words[0] == "$") {
            string cmd = words[1];
            if (cmd == "cd") {
                string dir = words[2];
                handle_cd(dir, dirs, curDir);
            } else if (cmd != "ls") {
                cout << "invalid command" << endl;
                throw exception();
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

void read_filesystem(const string inputFile, DirMap *dirs) {
    gen_dir_map(inputFile, dirs);
    find_dir_size((*dirs)["/"]);
}

// Problem 1: find all dirs with size <= a big size and add their sizes
int get_sum_of_small_dirs(DirMap *dirs) {
    int       sumSizeOfSmallDirs = 0;
    const int BIG_SIZE = 100000;
    for (auto item : (*dirs)) {
        string dirName = item.first;
        MyDir *dir = item.second;
        if (dir->size <= BIG_SIZE) {
            sumSizeOfSmallDirs += dir->size;
        }
    }
    cout << "sum of small dir sizes is: " << sumSizeOfSmallDirs;
    return 0;
}