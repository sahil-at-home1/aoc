#pragma once
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

namespace day8 {

enum class Sightline {
    RightToLeft,
    LeftToRight,
    TopToBot,
    BotToTop,
};

const std::vector<day8::Sightline> SightlineValues = {
    day8::Sightline::RightToLeft, day8::Sightline::LeftToRight,
    day8::Sightline::TopToBot, day8::Sightline::BotToTop};

class Tree {
  public:
    int                                 height;
    std::unordered_map<Sightline, bool> visibility;

  public:
    Tree(int height);
    ~Tree();
    bool                 is_visible();
    friend std::ostream &operator<<(std::ostream &out, Tree const &tree);
};

void check_left_to_right(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_right_to_left(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_top_to_bot(std::vector<std::vector<day8::Tree *>> *forest, int n);
void check_bot_to_top(std::vector<std::vector<day8::Tree *>> *forest, int n);

} // namespace day8