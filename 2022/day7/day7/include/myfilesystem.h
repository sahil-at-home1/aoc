#include "mydir.h"
#include <vector>

class MyFileSystem {
  private:
    MyDir               *rootDir;
    MyDir               *curDir;
    MyDir               *DFSDir;
    std::vector<MyDir *> DFSStack;

  public:
    MyFileSystem();
    // setters/getters
    const MyDir *getRootDir();
    const MyDir *getCurDir();
    MyDir       *getMutCurDir();
    void         setCurDir(std::string newDirName);
    // give next dir in DFS order
    const MyDir *DFSNextDir();
    // reset DFS search to root dir
    void DFSReset();
};