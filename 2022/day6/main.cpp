#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const size_t packet_length = 4;
    size_t chars_til_packet = 0;
    size_t valid_char_count = 0;
    string line = "";
    ifstream fin = ifstream("input.txt");

    // read input size_to a string
    while (getline(fin, line))
    {
        cout << "read a line." << endl;
    }
    fin.close();

    // parse each char of the string
    for (size_t i = 0; i < line.length(); i++)
    {
        if (i < packet_length)
        {
            continue;
        }
        // check if char is in previous packet chars
        valid_char_count += 1;
        for (size_t j = 1; j < (packet_length); j++)
        {
            if (line[i] == line[i - j])
            {
                valid_char_count = 0;
                break;
            }
        }

        if (valid_char_count >= 4)
        {
            chars_til_packet = i;
            break;
        }
    }
    cout << "Packet was detected after " << chars_til_packet << " characters" << endl;
}