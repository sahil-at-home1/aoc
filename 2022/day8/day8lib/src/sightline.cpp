#include "sightline.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

std::ostream &day8::operator<<(std::ostream &out, const day8::Sightline sl) {
    switch (sl) {
    case day8::Sightline::RightToLeft:
        out << "RightToLeft";
        break;
    case day8::Sightline::LeftToRight:
        out << "LeftToRight";
        break;
    case day8::Sightline::TopToBot:
        out << "TopToBot";
        break;
    case day8::Sightline::BotToTop:
        out << "BotToTop";
        break;
    };
    return out;
}
