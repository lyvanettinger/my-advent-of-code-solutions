#include "2025_solutions.h"

using namespace std;

void year_2025::day_6()
{
    cout << "----------------" << endl;
    cout << "Day 6: " << endl;

    //ifstream myfile("2025/2025_day_6_example.txt");
    ifstream myfile("2025/2025_day_6.txt");
    string line;

    cout << "Answer: " << endl;

    // Part 1
    //vector<vector<long long>> numbers;
    //vector<char> operators;
    //while (getline(myfile, line))
    //{
    //    // Collect numbers
    //    if (isdigit(line[0]))
    //    {
    //        vector<long long> line_numbers;
    //        string number;
    //        stringstream iss(line);

    //        while (iss >> number)
    //            line_numbers.push_back(stoll(number));

    //        numbers.push_back(line_numbers);
    //    }
    //    // Collect math operators
    //    else
    //    {
    //        string math_operator;
    //        stringstream iss(line);

    //        while (iss >> math_operator)
    //            operators.push_back(math_operator[0]);
    //    }
    //}

    //long long total = 0;
    //for (int i = 0; i < operators.size(); i++)
    //{
    //    long long sum = 0;
    //    if (operators[i] == '+')
    //    {
    //        for (vector<long long>& row : numbers)
    //            sum += row[i];
    //    }
    //    else if (operators[i] == '*')
    //    {
    //        sum = 1;
    //        for (vector<long long>& row : numbers)
    //            sum *= row[i];
    //    }
    //    cout << "SUM WITH " << operators[i] << ": " << sum << endl;
    //    total += sum;
    //}

    //cout << "TOTAL SUM: " << total << endl;


    // Part 2
    vector<string> lines;

    while (getline(myfile, line))
        lines.push_back(line);

    long long total_sum = 0;
    for (int i = 0; i < lines[lines.size() - 1].size();)
    {
        char math_operator = lines[lines.size() - 1][i];
        long long sum = (long long)(math_operator == '*');

        cout << "SUM" << math_operator << ": ";

        do
        {
            string str = "";
            for (int j = 0; j < lines.size() - 1; j++)
                str += lines[j][i];

            if (str.find_first_not_of(' ') != std::string::npos)
            {
                long long num = stoll(str);
                if (math_operator == '+')
                    sum += num;
                else
                    sum *= num;

                cout << num << " ";
            }

            i++;

            if (i == lines[0].size())
                break;

        } while (lines[lines.size() - 1][i] == ' ');

        cout << "= " << sum << endl;
        total_sum += sum;
    }

    cout << "TOTAL SUM: " << total_sum << endl;

    cout << "----------------" << endl;
}