#pragma once
#include "mydir.h"
#include "myfile.h"
#include <unordered_map>

namespace day7 {

using DirMap = std::unordered_map<std::string, MyDir *>;

int    find_dir_size(MyDir **curDir);
MyDir *gen_dirs(const std::string inputFile);
MyDir *read_filesystem(const std::string inputFile);
int    get_sum_of_small_dirs(MyDir *rootDir, int sumSizeOfSmallDirs);

} // namespace day7