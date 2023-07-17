#pragma once
#include "sightline.h"
#include "tree.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>

namespace day8 {

void check_left_to_right(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_right_to_left(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_top_to_bot(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_bot_to_top(std::vector<std::vector<day8::Tree *>> *forest, int n);

} // namespace day8