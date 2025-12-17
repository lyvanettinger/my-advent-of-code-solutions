#include "2025_solutions.h"

using namespace std;

void year_2025::day_1()
{
    cout << "----------------" << endl;
    cout << "Day 1: " << endl;

    ifstream myfile("2025/2025_day_1.txt");
    string line;

    // Start at 50
    // Count amount of 0
    // Wrap around on 99
    int current_dial = 50;
    const int max_dial = 99;
    int amount_zeros = 0;

    cout << "Answer: ";
    while (getline(myfile, line))
    {
        const char direction = line[0];
        const int offset = stoi(line.substr(1));

        for (int i = 0; i < offset; i++)
        {
            if (direction == 'R')
                current_dial++;
            else
                current_dial--;

            if ((current_dial % 100) == 0)
            {
                amount_zeros++;
            }
        }
    }
    cout << amount_zeros << endl;

    cout << "----------------" << endl;
}