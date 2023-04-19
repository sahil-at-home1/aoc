#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line = "";
    ifstream fin = ifstream("input.txt");

    // read input into a string
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();
}