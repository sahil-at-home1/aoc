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
    struct forArgs {
        int start;
        int end;
        int inc;
    };

    for (auto &sl : day8::SightlineValues) {
        forArgs sweep = {0, 0, 0};

        // switch sweep direction
        switch (sl) {
        case day8::Sightline::LeftToRight:
        case day8::Sightline::TopToBot:
            sweep = {0, forest->n, 1};
            break;
        case day8::Sightline::RightToLeft:
        case day8::Sightline::BotToTop:
            sweep = {forest->n - 1, -1, -1};
            break;
        }

        for (int i = 0; i < forest->n; i++) {
            std::vector<day8::Tree *> seen;
            int                       maxHeight = 0;
            for (int j = sweep.start; j != sweep.end; j += sweep.inc) {
                // switch order if sweeping through columns
                int row = i;
                int col = j;
                switch (sl) {
                case day8::Sightline::TopToBot:
                case day8::Sightline::BotToTop: {
                    row = j;
                    col = i;
                } break;
                default:
                    break;
                }
                day8::Tree *tree = forest->get_tree(row, col);
                // // calculate scenic factor
                tree->scenicFactor[sl] = 0;
                for (int k = seen.size() - 1; k > -1; k--) {
                    day8::Tree *seenTree = seen[0];
                    if (seenTree->height >= tree->height) {
                        tree->scenicFactor[sl] = k + 1;
                    }
                }
                // check visibility
                if (row == sweep.start || tree->height > maxHeight) {
                    tree->visibility[sl] = true;
                    maxHeight = tree->height;
                }
                seen.push_back(tree);
            }
            // reuse buffer for each sweep
            seen.clear();
        }
    }
}