#include "day8lib.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

void day8::check_left_to_right(std::vector<std::vector<day8::Tree *>> *forest,
                               int                                     n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int h = hStart; h != hEnd; h += hIncrement) {
        for (int v = vStart; v != vEnd; v += vIncrement) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (v == vStart) {
                tree->visibility[day8::Sightline::LeftToRight] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[day8::Sightline::LeftToRight] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void day8::check_right_to_left(std::vector<std::vector<day8::Tree *>> *forest,
                               int                                     n) {
    int hStart = n - 1;
    int hEnd = -1;
    int hIncrement = -1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int h = hStart; h != hEnd; h += hIncrement) {
        for (int v = vStart; v != vEnd; v += vIncrement) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (v == vStart) {
                tree->visibility[day8::Sightline::RightToLeft] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[day8::Sightline::RightToLeft] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void day8::check_top_to_bot(std::vector<std::vector<day8::Tree *>> *forest,
                            int                                     n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = 0;
    int vEnd = n;
    int vIncrement = 1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vIncrement) {
        for (int h = hStart; h != hEnd; h += hIncrement) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (h == hStart) {
                tree->visibility[day8::Sightline::TopToBot] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[day8::Sightline::TopToBot] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void day8::check_bot_to_top(std::vector<std::vector<day8::Tree *>> *forest,
                            int                                     n) {
    int hStart = 0;
    int hEnd = n;
    int hIncrement = 1;
    int vStart = n - 1;
    int vEnd = -1;
    int vIncrement = -1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vIncrement) {
        for (int h = hStart; h != hEnd; h += hIncrement) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            if (h == hStart) {
                tree->visibility[day8::Sightline::TopToBot] = true;
                continue;
            }
            // check if tree is taller than all other trees along sightline
            if (tree->height > maxHeight) {
                tree->visibility[day8::Sightline::TopToBot] = true;
                maxHeight = tree->height;
            }
        }
    }
}
