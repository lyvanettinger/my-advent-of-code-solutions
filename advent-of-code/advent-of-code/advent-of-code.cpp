#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

void BubbleSort(vector<int>& arr)
{
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void Day1()
{
    cout << "----------------" << endl;
    cout << "Day 1: " << endl;

    vector<int> numbers;

    ifstream myfile("input/'24/day1.txt");
    int number;
    while (myfile >> number)
        numbers.push_back(number);
    myfile.close();

    vector<int> lhs;
    vector<int> rhs;
    bool get_lhs = true;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (get_lhs)
        {
            lhs.push_back(numbers[i]);
            get_lhs = false;
        }
        else
        {
            rhs.push_back(numbers[i]);
            get_lhs = true;
        }
    }

    BubbleSort(lhs);
    BubbleSort(rhs);

    // puzzle 1
    int total = 0;
    for (int i = 0; i < lhs.size(); i++)
        total += abs(lhs[i] - rhs[i]);
    cout << "Puzzle 1: ";
    cout << total << '\n';

    // puzzle 2
    total = 0;
    int current_lhs = 0;
    int current_similarity_score = 0;
    for (int i = 0; i < lhs.size(); i++)
    {
        if (current_lhs != lhs[i])
            current_lhs = lhs[i];

        int similarity_count = 0;

        for (int j = 0; j < rhs.size(); j++)
        {
            if (current_lhs == rhs[j])
                similarity_count++;
        }

        total += current_lhs * similarity_count;
    }
    cout << "Puzzle 2: ";
    cout << total << '\n';
    cout << "----------------" << endl;
}

void Day2()
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

void Day3()
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

    {   // Puzzle 2
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

int main()
{
    Day1();
    Day2();
    Day3();

    cin.get();

    return 0;
}