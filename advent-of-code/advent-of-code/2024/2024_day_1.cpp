#include "2024_solutions.h"

using namespace std;

void bubble_sort(vector<int>& arr)
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

void year_2024::day_1()
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

    bubble_sort(lhs);
    bubble_sort(rhs);

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