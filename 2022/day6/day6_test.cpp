#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include "day6.hpp"

using namespace std;

int main()
{
    map<string, tuple<int, int>> INPUT_TO_RESULT = {
        {"bvwbjplbgvbhsrlpgdmjqwftvncz", tuple<int, int>(5, 23)},
        {"nppdvjthqldpwncqszvftbrmjlhg", tuple<int, int>(6, 23)},
        {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg", tuple<int, int>(10, 29)},
        {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw", tuple<int, int>(11, 26)},
    };
    vector<int> PACKET_LENGTHS = {4, 14};
    for (int i = 0; i < PACKET_LENGTHS.size(); i++)
    {
        int packet_length = PACKET_LENGTHS[i];
        for (const auto &kvpair : INPUT_TO_RESULT)
        {
            int got = get_packet_idx(kvpair.first, packet_length);
            int expected = i == 0 ? get<0>(kvpair.second) : get<1>(kvpair.second);
            if (got != expected)
            {
                cout << "TEST FAILURE on " << kvpair.first << ". ";
                cout << "Expected " << expected << "; got " << got;
                exit(1);
            }
        }
    }
    exit(0);
}