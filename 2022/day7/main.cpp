#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class MyFile
{
public:
    int size;
    std::string name;
};

class MyDir
{
public:
    int size;
    std::vector<MyFile> files;
    std::vector<MyDir> dirs;
};

int main()
{
    std::string line;
    std::ifstream f;

    f.open("day7/input.txt");
    if (!f.is_open())
    {
        std::cout << "could not open file" << std::endl;
        return 1;
    }

    while (getline(f, line))
    {
        std::cout << line << std::endl;
    }
    f.close();
}
