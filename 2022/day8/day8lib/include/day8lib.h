#pragma once
#include "forest.h"
#include "sightline.h"
#include "tree.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <vector>

namespace day8 {

void check_left_to_right(day8::Forest *forest);
void check_right_to_left(day8::Forest *forest);
void check_top_to_bot(day8::Forest *forest);
void check_bot_to_top(day8::Forest *forest);

} // namespace day8