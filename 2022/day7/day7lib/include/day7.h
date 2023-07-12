#pragma once
#include "mydir.h"
#include "myfile.h"
#include "myfilesystem.h"

namespace day7 {

int           set_dir_size(MyDir *curDir);
void          gen_dir_size(MyFileSystem *fs);
MyFileSystem *gen_filesystem(const std::string inputFile);
int           get_sum_of_small_dirs(MyFileSystem *fs);

} // namespace day7