#include "myfilesystem.h"
#include "mydir.h"

MyFileSystem::MyFileSystem() {
    this->rootDir = new MyDir("/", nullptr);
    this->curDir = this->rootDir;
    // prepare for DFS file system iteration
    this->DFSDir = this->rootDir;
    this->DFSStack = std::vector<MyDir *>();
    this->DFSStack.push_back(this->rootDir);
}

const MyDir *MyFileSystem::getRootDir() { return this->rootDir; }
const MyDir *MyFileSystem::getCurDir() { return this->curDir; }
MyDir       *MyFileSystem::getMutCurDir() { return this->curDir; }

void MyFileSystem::setCurDir(std::string newDirName) {
    // std::cout << "CURRENT DIRECTORY: " << this->curDir << std::endl;
    if (this->curDir == nullptr) {
        std::cout << "current directory is null" << std::endl;
        throw std::exception();
    }
    if (newDirName == "..") {
        if (this->curDir->parent == nullptr) {
            std::cout << "the current directory, \"" << curDir->path
                      << "\", has null parent" << std::endl;
            throw std::exception();
        }
        this->curDir = curDir->parent;
    } else {
        // check if dir in cur dir children
        if (this->curDir->name != newDirName &&
            !this->curDir->get_child_dir(newDirName)) {
            std::cout << "the destination dir, " << newDirName
                      << " not in current dir " << *curDir << " children"
                      << std::endl;
            throw std::exception();
        }
        // switch to specified dir from current dir children
        if (newDirName != "/") {
            this->curDir = this->curDir->get_child_dir(newDirName);
        }
    }
}

// returns nullptr on end of iteration
const MyDir *MyFileSystem::DFSNextDir() {
    if (this->DFSStack.empty()) {
        return nullptr;
    }
    // pop next dir to explore from stack
    this->DFSDir = this->DFSStack.back();
    this->DFSStack.pop_back();
    // add to stack of dirs to explore
    for (auto &item : this->DFSDir->get_child_dirs()) {
        this->DFSStack.push_back(item.second);
    }
    return this->DFSDir;
}

void MyFileSystem::DFSReset() {
    this->DFSDir = this->rootDir;
    this->DFSStack.clear();
}