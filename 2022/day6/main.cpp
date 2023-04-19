#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day6.hpp"

using namespace std;

int main()
{
    const size_t packet_length = 14;
    string line = "";
    ifstream fin = ifstream("input.txt");

    // read input size_to a string
    while (getline(fin, line))
    {
        cout << "read a line." << endl;
    }
    fin.close();

    int packet_idx = get_packet_idx(line, packet_length);
    cout << "Packet was detected after " << packet_idx << " characters" << endl;
}