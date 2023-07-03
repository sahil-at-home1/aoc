#pragma once
#include "mydir.h"
#include "myfile.h"
#include "myfilesystem.h"

namespace day7 {

int           find_dir_size(MyDir *curDir);
MyFileSystem *gen_filesystem(const std::string inputFile);
int           get_sum_of_small_dirs(MyFileSystem *fs);

} // namespace day7