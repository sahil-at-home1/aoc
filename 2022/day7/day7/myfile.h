#include <string>

class MyFile {
  public:
    int         size;
    std::string name;

  public:
    MyFile(std::string name, int size);
    friend std::ostream &operator<<(std::ostream &out, const MyFile &file);
};