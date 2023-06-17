#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class MyFile {
  public:
    int    size;
    string name;

  public:
    MyFile(string name, int size) {
        this->name = name;
        this->size = size;
    }
    friend std::ostream &operator<<(std::ostream &out, const MyFile &file) {
        out << "MyFile(" << file.name << ", " << file.size << ")";
        return out;
    }
};

class MyDir {
  public:
    int              size;
    vector<MyFile *> files;
    vector<MyDir *>  dirs;
    string           name;
    MyDir           *parent;

  public:
    MyDir(string name, MyDir *parent) {
        this->parent = parent;
        this->name = name;
        this->size = 0;
    }
    void                 add_dir(MyDir *dir) { this->dirs.push_back(dir); }
    void                 add_file(MyFile *file) { this->files.push_back(file); }
    friend std::ostream &operator<<(std::ostream &out, const MyDir &dir) {
        string parent_name = "N/A";
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

int find_dir_size(MyDir *curDir) {
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

int main() {
    string   line;
    ifstream f;

    // f.open("C:/Users/sahil/dev/aoc/2022/day7/input.txt");
    f.open("C:/Users/sahil/dev/aoc/2022/day7/ez_input.txt");
    if (!f.is_open()) {
        cout << "could not open file" << endl;
        return 1;
    }

    // map of names to dirs
    unordered_map<string, MyDir *> dirs;
    MyDir                         *cur_dir = nullptr;

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
            if (words[1] == "cd") {
                if (words[2] == "..") {
                    cur_dir = cur_dir->parent;
                } else {
                    // create new directory if never seen before
                    if (dirs.find(words[2]) == dirs.end()) {
                        MyDir *new_dir = new MyDir(words[2], cur_dir);
                        dirs.insert(make_pair(words[2], new_dir));
                    }
                    // switch to specified directory
                    cur_dir = dirs[words[2]];
                }
            } else if (words[1] != "ls") {
                throw exception("invalid command");
            }
        } else {
            // handle results of ls command
            if (words[0] == "dir") {
                // this line is a subdirectory
                MyDir *subdir = nullptr;
                // create new directory if never seen before
                if (dirs.find(words[1]) == dirs.end()) {
                    subdir = new MyDir(words[1], cur_dir);
                    dirs.insert(make_pair(words[1], subdir));
                } else {
                    subdir = dirs[words[1]];
                }
                cur_dir->add_dir(subdir);
            } else {
                // this line is a file, with size first
                int    size = stoi(words[0]);
                string file_name = words[1];
                cur_dir->add_file(new MyFile(file_name, size));
            }
        }
    }

    // find size of all dirs, starting at root
    find_dir_size(dirs["/"]);

    for (auto item : dirs) {
        cout << item.first << " : " << *(item.second) << endl;
    }

    f.close();
}
