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
};

class MyDir {
  public:
    int              size;
    vector<MyFile *> files;
    vector<MyDir *>  dirs;
    string           name;

  public:
    MyDir(string name) { this->name = name; }
    void add_file(MyFile *file) { this->files.push_back(file); }
    void add_dir(MyDir *dir) { this->dirs.push_back(dir); }
};

int main() {
    string   line;
    ifstream f;

    f.open("day7/input.txt");
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
        int            start = 0;
        int            end = line.find(delim);
        while (end != string::npos) {
            words.push_back(line.substr(start, end + 1));
        }

        // check what command was given
        if (words[0] == "$") {
            if (words[1] == "ls") {
                // pass
            } else if (words[1] == "cd") {
                cur_dir = dirs[words[2]];
            } else {
                throw exception("invalid command");
            }
        } else {
            if (words[1] == "dir") {
                cur_dir->add_dir(new MyDir(words[2]));
            } else {
                cur_dir->add_file(new MyFile(words[2], stoi(words[1])));
            }
        }
    }

    for (auto item : dirs) {
        cout << item.first << " : " << item.second << endl;
    }

    f.close();
}

void handle_cd() {}