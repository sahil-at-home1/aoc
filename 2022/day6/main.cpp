#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "day6.hpp"

using namespace std;

int main()
{
    const int packet_length = 14;
    string line = "";
    ifstream fin = ifstream("input.txt");

    // read input into a string
    while (getline(fin, line))
    {
        cout << "read a line." << endl;
    }
    fin.close();

    int packet_idx = get_packet_idx(line, packet_length);
    cout << "Packet was detected after " << packet_idx << " characters" << endl;
}