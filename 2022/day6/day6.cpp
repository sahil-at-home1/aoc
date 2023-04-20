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
        // check if char is in previous packet chars
        char test_char = line[i];
        valid_char_count += 1;
        for (int j = 1; j < packet_length || j > i; j++)
        {

            char compare_char = line[i - j];
            if (test_char == compare_char)
            {
                if (i < packet_length)
                {
                    valid_char_count -= (i + 2) - j;
                }
                else
                {
                    valid_char_count -= packet_length - j;
                }
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
