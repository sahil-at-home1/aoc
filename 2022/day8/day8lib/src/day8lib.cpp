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
    int hInc = 1;
    int vStart = 0;
    int vEnd = n;
    int vInc = 1;

    int maxHeight = 0;
    for (int h = hStart; h != hEnd; h += hInc) {
        for (int v = vStart; v != vEnd; v += vInc) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            // check if tree is taller than all other trees along sightline
            if (v == vStart || tree->height > maxHeight) {
                tree->visibility[day8::Sightline::LeftToRight] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void day8::check_right_to_left(std::vector<std::vector<day8::Tree *>> *forest,
                               int                                     n) {
    int rowStart = 0;
    int rowEnd = n;
    int rowInc = 1;
    // check last col first
    int colStart = n - 1;
    int colEnd = -1;
    int colInc = -1;

    int maxHeight = 0;
    for (int row = rowStart; row != rowEnd; row += rowInc) {
        // sweep across columns for each row, from right to left
        for (int col = colStart; col != colEnd; col += colInc) {
            day8::Tree *tree = (*forest)[row][col];
            // check if tree is on edge
            // check if tree is taller than all other trees along sightline
            if (col == colStart || tree->height > maxHeight) {
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
    int hInc = 1;
    int vStart = 0;
    int vEnd = n;
    int vInc = 1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vInc) {
        for (int h = hStart; h != hEnd; h += hInc) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            // check if tree is taller than all other trees along sightline
            if (h == hStart || tree->height > maxHeight) {
                tree->visibility[day8::Sightline::TopToBot] = true;
                maxHeight = tree->height;
            }
        }
    }
}

void day8::check_bot_to_top(std::vector<std::vector<day8::Tree *>> *forest,
                            int                                     n) {
    int hStart = n - 1;
    int hEnd = -1;
    int hInc = -1;
    int vStart = 0;
    int vEnd = n;
    int vInc = 1;

    int maxHeight = 0;
    for (int v = vStart; v != vEnd; v += vInc) {
        for (int h = hStart; h != hEnd; h += hInc) {
            day8::Tree *tree = (*forest)[h][v];
            // check if tree is on edge
            // check if tree is taller than all other trees along sightline
            if (h == hStart || tree->height > maxHeight) {
                tree->visibility[day8::Sightline::BotToTop] = true;
                maxHeight = tree->height;
            }
        }
    }
}
