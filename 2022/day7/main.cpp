#include <iostream>
#include <vector>

class MyFile {
public:
  int size;
  std::string name;
};

class MyDir {
public:
  int size;
  std::vector<MyFile> files;
  std::vector<MyDir> dirs;
};

int main() { std::cout << "Hello world!" << std::endl; }
