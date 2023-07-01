#include "day7.h"

int main() {
    std::string inputFile = "C:/users/sahil/dev/aoc/2022/day7/input.txt";
    // std::string   inputFile =
    // "C:/users/sahil/dev/aoc/2022/day7/ez_input.txt";
    day7::DirMap *dirs = new day7::DirMap();

    day7::read_filesystem(inputFile, dirs);
    int sumOfSmallDirs = day7::get_sum_of_small_dirs(dirs);

    std::cout << "(Problem 1) The answer to the real input is: "
              << sumOfSmallDirs << std::endl;
}
