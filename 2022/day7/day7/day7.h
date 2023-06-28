#include "mydir.h"
#include "myfile.h"
#include <unordered_map>

using DirMap = std::unordered_map<std::string, MyDir *>;

int  find_dir_size(MyDir *curDir);
void read_filesystem(const std::string inputFile, DirMap *dirs);
void gen_dir_map(const std::string inputFile, DirMap *dirs);
int  get_sum_of_small_dirs(DirMap *dirs);