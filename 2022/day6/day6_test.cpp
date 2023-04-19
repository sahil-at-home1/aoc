#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "day6.hpp"

using namespace std;

int main()
{
    map<string, int> INPUT_TO_RESULT = {
        {"mjqjpqmgbljsphdztnvjfqwrcgsmlb", 19},
        {"bvwbjplbgvbhsrlpgdmjqwftvncz", 23},
        {"nppdvjthqldpwncqszvftbrmjlhg", 23},
        {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", 19},
        {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", 19},
    };
    vector<int> PACKET_LENGTHS = {4, 14};
    for (int &packet_length : PACKET_LENGTHS)
    {
        for (const auto &kvpair : INPUT_TO_RESULT)
        {
            int got = get_packet_idx(kvpair.first, packet_length);
            if (got != kvpair.second)
            {
                cout << "TEST FAILURE on " << kvpair.first << ". ";
                cout << "Expected " << kvpair.second << "; got " << got;
                exit(1);
            }
        }
    }
    exit(0);
}