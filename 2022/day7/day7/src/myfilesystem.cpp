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

void MyFileSystem::SetCurDir(std::string newDirName) {
    // check if dir in cur dir children
    if (this->curDir->name != newDirName &&
        this->curDir->get_child_dir(destDir)) {
        std::cout << "the destination dir, " << newDirName
                  << " not in current dir " << this->curDir << " children"
                  << std::endl;
        throw std::exception();
    }
    this->curDir = newDirName
}

// returns nullptr on end of iteration
const MyDir *MyFileSystem::next(std::function<void(int)>) {
    if (this->DFSStack.empty()) {
        return nullptr;
    }
    // pop next dir to explore from stack
    this->DFSDir = this->DFSStack.back();
    this->DFSStack.pop_back();
    // add to stack of dirs to explore
    for (auto &item : this->DFSDir->get_child_dirs()) {
        stack.push_back(item.second);
    }
    return this->DFSDir;
}