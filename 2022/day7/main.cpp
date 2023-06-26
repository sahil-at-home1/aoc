#include "day7.h"

using namespace std;

int main() {
    // string  inputFile = "C:/users/sahil/dev/aoc/2022/day7/input.txt";
    string  inputFile = "C:/users/sahil/dev/aoc/2022/day7/ez_input.txt";
    DirMap *dirs = new DirMap();

    read_filesystem(inputFile, dirs);
    get_sum_of_small_dirs(dirs);

    cout << "(Problem 1) The answer to the real input is: " << endl;
}
