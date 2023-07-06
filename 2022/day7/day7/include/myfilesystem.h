#include "mydir.h"
#include <vector>

namespace day7 {

class MyFileSystem {
  private:
    MyDir               *rootDir;
    MyDir               *curDir;
    MyDir               *DFSDir;
    std::vector<MyDir *> DFSStack;

  public:
    MyFileSystem();
    // setters/getters
    MyDir *getRootDir();
    MyDir *getCurDir();
    void   setCurDir(std::string newDirName);
    // give next dir in DFS order
    MyDir *DFSNextDir();
    // reset DFS search to root dir
    void DFSReset();
    // common commands
    void mkdir(std::string newDirName);
    void touch(std::string newFileName, int newFileSize);
};
} // namespace day7