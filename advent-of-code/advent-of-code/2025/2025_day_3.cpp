#include "2025_solutions.h"

using namespace std;

void year_2025::day_3()
{
    cout << "----------------" << endl;
    cout << "Day 3: " << endl;

    //ifstream myfile("2025/2025_day_3_example.txt");
    ifstream myfile("2025/2025_day_3.txt");
    string line;


    // part 1
    /*cout << "Answer: " << endl;
    int total_joltage = 0;
    while (getline(myfile, line))
    {
        cout << line;
        int highest_joltage = 0;
        for (string::iterator it = line.begin(); it != line.end(); it++)
        {
            for (string::iterator it2 = it + 1; it2 != line.end(); it2++)
            {
                string s = "";
                s += *it;
                s += *it2;

                int current_joltage = stoi(s);
                highest_joltage = (current_joltage > highest_joltage) ? current_joltage : highest_joltage;

                if (highest_joltage == 99)
                    break;
            }
            if (highest_joltage == 99)
                break;
        }

        cout << ", JOLTAGE: " << highest_joltage << endl;

        total_joltage += highest_joltage;
    }*/

    // part 2
    const int max_batteries = 12;
    cout << "Answer: " << endl;
    long long total_joltage = 0;
    while (getline(myfile, line))
    {
        long long highest_joltage = 0;
        string::iterator total_offset = line.begin();

        cout << "NUMBER: " << line << endl;

        for (int i = max_batteries - 1; i >= 0; i--)
        {
            int highest_digit = 0;
            for (string::iterator current_offset = total_offset; current_offset < line.end() - i; current_offset++)
            {
                int current_digit = *current_offset - '0';
                if (current_digit > highest_digit)
                {
                    highest_digit = current_digit;
                    total_offset = current_offset + 1;
                }

                if (highest_digit == 9)
                    break;
            }

            highest_joltage += (long long)(pow(10, i)) * highest_digit;
            cout << "NUMBER JOLTAGE: " << highest_joltage << endl;
        }

        total_joltage += highest_joltage;
        cout << "TOTAL JOLTAGE: " << total_joltage << endl;
    }

    cout << "FINAL JOLTAGE: " << total_joltage << endl;

    cout << "----------------" << endl;
}