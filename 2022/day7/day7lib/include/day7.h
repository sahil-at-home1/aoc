#pragma once
#include "mydir.h"
#include "myfile.h"
#include "myfilesystem.h"

namespace day7 {

int           set_dir_size(MyDir *curDir);
void          gen_dir_size(MyFileSystem *fs);
MyFileSystem *gen_filesystem(const std::string inputFile);
int           get_sum_of_small_dirs(MyFileSystem *fs);
int           get_size_of_smallest_dir_to_free_space(MyFileSystem *fs);

} // namespace day7