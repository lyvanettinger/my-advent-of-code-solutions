#include "2024_solutions.h"

using namespace std;

void year_2024::day_3()
{
    cout << "----------------" << endl;
    cout << "Day 3: " << endl;

    {   // Puzzle 1
        ifstream myfile("input/'24/day3.txt");
        string line;

        int total = 0;

        while (getline(myfile, line))
        {
            int offset = 0;
            while ((offset = line.find("mul(", offset)) != string::npos)
            {
                string nums;
                bool first_num = false;
                bool is_valid = false;
                for (int i = offset + 4; i != line.size(); i++)
                {
                    if (isdigit(line[i]))
                    {
                        nums += line[i];
                    }
                    else if (!nums.empty() && line[i] == ',')
                    {
                        if (first_num)
                            continue;

                        first_num = true;
                        nums += ',';
                    }
                    else if (!nums.empty() && line[i] == ')')
                    {
                        if (!first_num && !isdigit(nums[nums.size() - 1]))
                            continue;

                        is_valid = true;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }

                if (is_valid)
                {
                    int lhs, rhs;
                    sscanf_s(nums.c_str(), "%i,%i", &lhs, &rhs);

                    total += lhs * rhs;
                }

                line[offset] = '/';

                offset++;
            }
        }
        myfile.close();

        cout << "Puzzle 1: ";
        cout << total << '\n';
    }

    {   // Puzzle 2 // IN PROGRESS
        ifstream myfile("input/'24/day3.txt");
        string line;

        int total = 0;

        while (getline(myfile, line))
        {
            int offset = 0;
            while ((offset = line.find("do()", offset)) != string::npos)
            {
                int dont_offset = line.find("don't()", offset);

                int mul_offset = offset;
                while ((mul_offset = line.find("mul(", mul_offset)) < dont_offset)
                {
                    string nums;
                    bool first_num = false;
                    bool is_valid = false;
                    for (int i = mul_offset + 4; i != line.size(); i++)
                    {
                        if (isdigit(line[i]))
                        {
                            nums += line[i];
                        }
                        else if (!nums.empty() && line[i] == ',')
                        {
                            if (first_num)
                                continue;

                            first_num = true;
                            nums += ',';
                        }
                        else if (!nums.empty() && line[i] == ')')
                        {
                            if (!first_num && !isdigit(nums[nums.size() - 1]))
                                continue;

                            is_valid = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if (is_valid)
                    {
                        int lhs, rhs;
                        sscanf_s(nums.c_str(), "%i,%i", &lhs, &rhs);

                        total += lhs * rhs;
                    }

                    line[mul_offset] = '/';

                    mul_offset++;
                }

                offset = dont_offset;
            }
        }
        myfile.close();

        cout << "Puzzle 2: ";
        cout << total << '\n';
    }

    cout << "----------------" << endl;
}