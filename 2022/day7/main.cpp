#include "day7.h"

int main() {
    // std::string inputFile = "C:/users/sahil/dev/aoc/2022/day7/input.txt";
    // std::string inputFile = "C:/users/sahil/dev/aoc/2022/day7/ez_input.txt";

    std::string inputFile = "/home/sahil/dev/aoc/2022/day7/input.txt";
    // std::string inputFile =
    // "/home/users/sahil/dev/aoc/2022/day7/ez_input.txt";

    day7::MyFileSystem *fs = day7::gen_filesystem(inputFile);

    int sumOfSmallDirs = day7::get_sum_of_small_dirs(fs);

    std::cout << "(Problem 1) The answer to the real input is: "
              << sumOfSmallDirs << std::endl;

    std::cout << *fs << std::endl;
}
