#include "2025_solutions.h"

using namespace std;

bool invalid_id(long long id)
{
    return regex_match(to_string(id), regex("^(\\d+)\\1$"));
}

bool invalid_id_2(long long id)
{
    return regex_match(to_string(id), regex("^(\\d+)\\1+$"));
}

void year_2025::day_2()
{
    cout << "----------------" << endl;
    cout << "Day 2: " << endl;

    ifstream myfile("2025/2025_day_2.txt");
    //ifstream myfile("2025/2025_day_2_p1_example.txt");
    string input;
    getline(myfile, input);

    long long total_invalid_ids = 0;

    cout << "Answer: " << endl;
    string::iterator it = input.begin();
    while (it != input.end())
    {
        string min = "";
        string max = "";
        while (*it != '-')
        {
            min += *it;
            it++;
        }

        it++;

        while (*it != ',')
        {
            max += *it;
            it++;

            if (it == input.end())
                break;
        }

        if(it != input.end())
            it++;

        for (long long i = stoll(min); i <= stoll(max); i++)
        {
            if (invalid_id_2(i))
                total_invalid_ids += i;
        }

        cout << "Test: MIN: " << min << ", MAX: " << max << ", INVALID ID TOTAL: " << total_invalid_ids << endl;
        //break;
    }
    cout << total_invalid_ids << endl;

    cout << "----------------" << endl;
}