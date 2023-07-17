#pragma once
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

namespace day8 {

enum class Sightline {
    RightToLeft,
    LeftToRight,
    TopToBot,
    BotToTop,
};

std::ostream &operator<<(std::ostream &out, const day8::Sightline sl);

const std::vector<day8::Sightline> SightlineValues = {
    day8::Sightline::RightToLeft, day8::Sightline::LeftToRight,
    day8::Sightline::TopToBot, day8::Sightline::BotToTop};

}