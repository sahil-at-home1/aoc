#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

class MyFile {
  public:
    int         size;
    std::string name;
};

class MyDir {
  public:
    int                 size;
    std::vector<MyFile> files;
    std::vector<MyDir>  dirs;

  public:
    void add_file();
    void add_dir();
};

int main() {
    std::string   line;
    std::ifstream f;

    f.open("day7/input.txt");
    if (!f.is_open()) {
        std::cout << "could not open file" << std::endl;
        return 1;
    }

    // read file line by line
    while (getline(f, line)) {
        // split line by spaces
        const std::string        delim = " ";
        std::vector<std::string> words;
        int                      start = 0;
        int                      end = line.find(delim);
        while (end != std::string::npos) {
            words.push_back(line.substr(start, end + 1));
        }

        std::unordered_map<std::string, MyDir *> dirs; // map of names to dirs
        MyDir                                   *cur_dir = new MyDir;
        // check what command was given
        if (words[0] == "$") {
            if (words[0] == "ls") {
                // pass
            } else if (words[0] == "cd") {
                cur_dir = dirs[words[1]];
            } else {
                throw std::exception("invalid command");
            }
        } else {
            // its a directory list
        }
    }
    f.close();
}

void handle_cd() {}