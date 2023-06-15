#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
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
};

int main() {
    std::string   line;
    std::ifstream f;

    f.open("day7/input.txt");
    if (!f.is_open()) {
        std::cout << "could not open file" << std::endl;
        return 1;
    }

    while (getline(f, line)) {
        // split line by spaces
        const std::string        delim = " ";
        std::vector<std::string> words;
        int                      start = 0;
        int                      end = line.find(delim);
        while (end != std::string::npos) {
            words.push_back(line.substr(start, end + 1));
        }
        // check what command was given
        if (words[0] == "$") {
            if (words[0] == "ls") {
            } else if (words[0] == "cd") {
            } else {
                throw std::exception("invalid command");
            }
        } else {
            // its a directory list
        }
    }
    f.close();
}
