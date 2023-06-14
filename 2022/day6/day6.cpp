#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day6.hpp"

using namespace std;

int get_packet_idx(string line, int packet_length)
{
    int packet_idx = 0;
    int valid_char_count = 0;

    // parse each char of the string with a char behind it
    for (int i = 1; i < line.length(); i++)
    {
        valid_char_count += 1;
        // check if current char is in previous packet chars
        // if it is, the valid packet char count must restart
        // from after the position that matching char was found
        char curr_char = line[i];
        for (int j = 1; j < packet_length; j++)
        {
            int test_char_idx = i - j;
            if (test_char_idx < 0)
            {
                break;
            }
            char test_char = line[test_char_idx];
            if (test_char == curr_char)
            {
                valid_char_count -= i - test_char_idx;
                break;
            }
        }

        if (valid_char_count >= packet_length)
        {
            packet_idx = i;
            break;
        }
    }
    return int(packet_idx);
}
