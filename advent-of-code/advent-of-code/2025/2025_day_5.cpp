#include "2025_solutions.h"

using namespace std;

void year_2025::day_5()
{
    cout << "----------------" << endl;
    cout << "Day 5: " << endl;

    //ifstream myfile("2025/2025_day_5_example.txt");
    ifstream myfile("2025/2025_day_5.txt");
    string line;

    // first=min, second=max
    vector<pair<long long, long long>> fresh_ranges;

    cout << "Answer: " << endl;

    // Part 1
    //bool process_id = false;
    //int fresh_ingredient_count = 0;
    //while (getline(myfile, line))
    //{
    //    if (line.empty())
    //    {
    //        process_id = true;
    //        continue;
    //    }

    //    // Store ranges
    //    if (!process_id)
    //    {
    //        smatch m;
    //        if (regex_match(line, m, regex("^(\\d+)-(\\d+)$")))
    //        {
    //            fresh_ranges.push_back(pair<long long, long long>(stoll(m[1]), stoll(m[2])));
    //            cout << "MIN: " << m[1] << ", MAX: " << m[2] << endl;
    //        }
    //    }
    //    // Process IDs
    //    else
    //    {
    //        long long id = stoll(line);
    //        for (pair<long long, long long> range : fresh_ranges)
    //        {
    //            if (id == clamp(id, range.first, range.second))
    //            {
    //                cout << "ID: " << id << ", RANGE: " << range.first << "-" << range.second << endl;
    //                fresh_ingredient_count++;
    //                break;
    //            }
    //        }
    //    }
    //}
    //cout << "TOTAL FRESH INGREDIENTS: " << fresh_ingredient_count << endl;

    // Part 2
    long long total_fresh_ids = 0;
    while (getline(myfile, line))
    {
        if (line.empty())
            break;

        smatch m;
        if (regex_match(line, m, regex("^(\\d+)-(\\d+)$")))
            fresh_ranges.push_back(pair<long long, long long>(stoll(m[1]), stoll(m[2])));
    }

    ranges::sort(fresh_ranges);

    vector<pair<long long, long long>>::iterator previous_range = fresh_ranges.begin();
    for (vector<pair<long long, long long>>::iterator it = fresh_ranges.begin() + 1; it != fresh_ranges.end();)
    {
        if (it->first == clamp(it->first, previous_range->first, previous_range->second))
        {
            previous_range->second = (it->second > previous_range->second) ? it->second : previous_range->second;
            it = fresh_ranges.erase(it);
        }
        else
        {
            previous_range = it;
            it++;
        }
    }

    for (pair<long long, long long> range : fresh_ranges)
    {
        cout << "RANGE: " << range.first << "-" << range.second << endl;
        total_fresh_ids += (range.second - range.first) + 1;
    }


    cout << "TOTAL FRESH IDS: " << total_fresh_ids << endl;

    cout << "----------------" << endl;
}