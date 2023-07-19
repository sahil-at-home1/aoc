#include "day8lib.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>

void day8::check_tree_visibilities(day8::Forest *forest) {
    for (auto &sightline : day8::SightlineValues) {
        switch (sightline) {
        case day8::Sightline::LeftToRight:
            day8::check_left_to_right(forest);
            break;
        case day8::Sightline::RightToLeft:
            day8::check_right_to_left(forest);
            break;
        case day8::Sightline::TopToBot:
            day8::check_top_to_bot(forest);
            break;
        case day8::Sightline::BotToTop:
            day8::check_bot_to_top(forest);
            break;
        }
    }
}

void day8::check_left_to_right(day8::Forest *forest) {
    auto sl = day8::Sightline::LeftToRight;
    int  rowStart = 0;
    int  rowEnd = forest->n;
    int  rowInc = 1;
    int  colStart = 0;
    int  colEnd = forest->n;
    int  colInc = 1;

    int maxHeight = 0;
    int maxHeightPos = 0;
    for (int row = rowStart; row != rowEnd; row += rowInc) {
        for (int col = colStart; col != colEnd; col += colInc) {
            day8::Tree *tree = forest->get_tree(row, col);
            // check if tree is on edge
            if (col == colStart) {
                tree->scenicFactor[sl] = 0;
            }
            // check if tree is taller than all other trees along sightline
            if (col == colStart || tree->height > maxHeight) {
                // calculate partial visibility
                tree->visibility[sl] = true;
                maxHeight = tree->height;
                // calculate scenic factor
                tree->scenicFactor[sl] = col - maxHeightPos;
                if (tree->scenicFactor[sl] < 0) {
                    tree->scenicFactor[sl] = tree->scenicFactor[sl] * -1;
                }
                maxHeightPos = col;
            }
        }
    }
}

void day8::check_right_to_left(day8::Forest *forest) {
    auto sl = day8::Sightline::RightToLeft;
    int  rowStart = 0;
    int  rowEnd = forest->n;
    int  rowInc = 1;
    int  colStart = forest->n - 1;
    int  colEnd = -1;
    int  colInc = -1;

    for (int row = rowStart; row != rowEnd; row += rowInc) {
        std::vector<day8::Tree *> seen;
        // start sweep
        int maxHeight = 0;
        for (int col = colStart; col != colEnd; col += colInc) {
            day8::Tree *tree = forest->get_tree(row, col);
            // calculate scenic factor (find distance to first tree with height >= this height)
            tree->scenicFactor[sl] = 0;
            for (int i = seen.size() - 1; i > -1; i--) {
                day8::Tree *seenTree = seen[0];
                if (seenTree->height >= tree->height) {
                    tree->scenicFactor[sl] = i + 1;
                }
            }
            // check visibility
            if (col == colStart || tree->height > maxHeight) {
                tree->visibility[sl] = true;
                maxHeight = tree->height;
            }
            seen.push_back(tree);
        }
        // reuse buffer for each sweep
        seen.clear();
    }
}

void day8::check_top_to_bot(day8::Forest *forest) {
    auto sl = day8::Sightline::TopToBot;
    int  rowStart = 0;
    int  rowEnd = forest->n;
    int  rowInc = 1;
    int  colStart = 0;
    int  colEnd = forest->n;
    int  colInc = 1;

    int maxHeight = 0;
    int maxHeightPos = 0;
    for (int col = colStart; col != colEnd; col += colInc) {
        for (int row = rowStart; row != rowEnd; row += rowInc) {
            day8::Tree *tree = forest->get_tree(row, col);
            // check if tree is on edge
            if (row == rowStart) {
                tree->scenicFactor[sl] = 0;
            }
            // check if tree is taller than all other trees along sightline
            if (row == rowStart || tree->height > maxHeight) {
                // calculate partial visibility
                tree->visibility[sl] = true;
                maxHeight = tree->height;
                // calculate scenic factor
                tree->scenicFactor[sl] = col - maxHeightPos;
                if (tree->scenicFactor[sl] < 0) {
                    tree->scenicFactor[sl] = tree->scenicFactor[sl] * -1;
                }
                maxHeightPos = col;
            }
        }
    }
}

void day8::check_bot_to_top(day8::Forest *forest) {
    auto sl = day8::Sightline::BotToTop;
    int  rowStart = forest->n - 1;
    int  rowEnd = -1;
    int  rowInc = -1;
    int  colStart = 0;
    int  colEnd = forest->n;
    int  colInc = 1;

    int maxHeight = 0;
    int maxHeightPos = 0;
    for (int col = colStart; col != colEnd; col += colInc) {
        for (int row = rowStart; row != rowEnd; row += rowInc) {
            day8::Tree *tree = forest->get_tree(row, col);
            // check if tree is on edge
            if (row == rowStart) {
                tree->scenicFactor[sl] = 0;
            }
            // check if tree is taller than all other trees along sightline
            if (row == rowStart || tree->height > maxHeight) {
                // calculate partial visibility
                tree->visibility[sl] = true;
                maxHeight = tree->height;
                // calculate scenic factor
                tree->scenicFactor[sl] = col - maxHeightPos;
                if (tree->scenicFactor[sl] < 0) {
                    tree->scenicFactor[sl] = tree->scenicFactor[sl] * -1;
                }
                maxHeightPos = col;
            }
        }
    }
}
