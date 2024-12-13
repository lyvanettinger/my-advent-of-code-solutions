#include "2024_solutions.h"

using namespace std;

void year_2024::day_2()
{
    cout << "----------------" << endl;
    cout << "Day 2: " << endl;

    ifstream myfile("input/'24/day2.txt");
    string line;

    int safe_count_one = 0;
    int safe_count_two = 0;
    while (getline(myfile, line))
    {
        istringstream iss(line);
        vector<int> v;
        int n;
        while (iss >> n)
            v.push_back(n);

        // Puzzle 1
        bool is_increasing = true;
        if (v[0] > v[1])
            is_increasing = false;

        bool is_safe = true;
        int previous_number = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            int dif = abs(previous_number - v[i]);
            if ((dif == 0) ||
                (dif > 3) ||
                (previous_number > v[i] && is_increasing) ||
                (previous_number < v[i] && !is_increasing))
            {
                is_safe = false;
                break;
            }

            previous_number = v[i];
        }

        if (is_safe)
            safe_count_one++;

        // Puzzle 2
        for (int i = 0; i < v.size(); i++)
        {
            is_safe = true;
            vector<int> v_copy = v;
            v_copy.erase(v_copy.begin() + i);

            is_increasing = true;
            if (v_copy[0] > v_copy[1])
                is_increasing = false;

            previous_number = v_copy[0];
            for (int j = 1; j < v_copy.size(); j++)
            {
                int dif = abs(previous_number - v_copy[j]);
                if ((dif == 0) ||
                    (dif > 3) ||
                    (previous_number > v_copy[j] && is_increasing) ||
                    (previous_number < v_copy[j] && !is_increasing))
                {
                    is_safe = false;
                    break;
                }

                previous_number = v_copy[j];
            }

            if (is_safe)
                break;
        }

        if (is_safe)
            safe_count_two++;
    }
    myfile.close();

    cout << "Puzzle 1: ";
    cout << safe_count_one << '\n';

    cout << "Puzzle 2: ";
    cout << safe_count_two << '\n';

    cout << "----------------" << endl;
}