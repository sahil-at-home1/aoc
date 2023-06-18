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

  public:
    MyFile(std::string name, int size) {
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
    int                   size;
    std::vector<MyFile *> files;
    std::vector<MyDir *>  dirs;
    std::string           name;
    MyDir                *parent;

  public:
    MyDir(std::string name, MyDir *parent) {
        this->parent = parent;
        this->name = name;
        this->size = 0;
    }
    void                 add_dir(MyDir *dir) { this->dirs.push_back(dir); }
    void                 add_file(MyFile *file) { this->files.push_back(file); }
    friend std::ostream &operator<<(std::ostream &out, const MyDir &dir) {
        std::string parent_name = "N/A";
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

using DirMap = unordered_map<string, MyDir *>;

int  find_dir_size(MyDir *curDir);
int  handle_ls_dir(const string name, DirMap dirs, MyDir *curDir);
int  handle_ls_file(const int size, const string name, MyDir *curDir);
int  handle_cd_dir(const string dir, DirMap dirs, MyDir *curDir);
void read_filesystem(const string input_file, DirMap *dirs);
int  get_sum_of_small_dirs(DirMap);
