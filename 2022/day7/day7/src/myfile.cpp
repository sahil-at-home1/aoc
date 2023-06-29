#include "myfile.h"
#include <iostream>
#include <stdio.h>

MyFile::MyFile(std::string name, int size) {
    this->name = name;
    this->size = size;
}

std::ostream &operator<<(std::ostream &out, const MyFile &file) {
    out << "MyFile(";
    out << file.name << ", ";
    out << file.size << ")" << std::endl;
    return out;
}