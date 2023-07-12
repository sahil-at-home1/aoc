add_library(day7lib
    src/myfile.cpp 
    src/mydir.cpp 
    src/myfilesystem.cpp 
    src/day7.cpp
    )

target_include_directories(day7lib PUBLIC include)