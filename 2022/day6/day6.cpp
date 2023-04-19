#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day6.hpp"

using namespace std;

int get_packet_idx(string line, size_t packet_length)
{
    size_t packet_idx = 0;
    size_t valid_char_count = 0;

    // parse each char of the string
    for (size_t i = (packet_length - 1); i < line.length(); i++)
    {
        // check if char is in previous packet chars
        valid_char_count += 1;
        for (size_t j = 1; j < packet_length; j++)
        {
            if (line[i] == line[i - j])
            {
                valid_char_count = 0;
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
