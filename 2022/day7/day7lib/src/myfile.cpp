#include "myfile.h"
#include <iostream>
#include <stdio.h>

day7::MyFile::MyFile(std::string name, int size) {
    this->name = name;
    this->size = size;
}

std::ostream &day7::operator<<(std::ostream &out, const day7::MyFile &file) {
    out << file.name << ", ";
    out << file.size << std::endl;
    return out;
}