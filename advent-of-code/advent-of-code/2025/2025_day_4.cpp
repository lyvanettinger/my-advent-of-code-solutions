#include "2025_solutions.h"

using namespace std;

void year_2025::day_4()
{
    cout << "----------------" << endl;
    cout << "Day 4: " << endl;

    //ifstream myfile("2025/2025_day_4_example.txt");
    ifstream myfile("2025/2025_day_4.txt");
    string line;
    vector<vector<bool>> roll_grid;
    const int max_surrounding_rolls = 4;

    vector<pair<int, int>> cell_check = {
        pair<int, int>(-1, -1), pair<int, int>(0, -1), pair<int, int>(1, -1), 
        pair<int, int>(-1, 0), pair<int, int>(1, 0), 
        pair<int, int>(-1, 1), pair<int, int>(0, 1), pair<int, int>(1, 1) 
    };

    cout << "Answer: ";
    // Collect data
    while (getline(myfile, line))
    {
        vector<bool> roll_row;
        for (string::iterator it = line.begin(); it != line.end(); it++)
            roll_row.push_back(*it == '@');

        roll_grid.push_back(roll_row);
    }

    int total_accessible_rolls = 0;
    int rolls_accessed = 0;

    // Interpret data
    do 
    {
        rolls_accessed = 0;
        for (int y = 0; y < roll_grid.size(); y++)
        {
            int accessible_rolls = 0;

            for (int x = 0; x < roll_grid[y].size(); x++)
            {
                if (roll_grid[y][x])
                {
                    int surrounding_rolls = 0;

                    // Check surrounding shelfs
                    for (pair<int, int> offset : cell_check)
                    {
                        int offset_x = x + offset.first;
                        int offset_y = y + offset.second;
                        if (offset_x >= 0 && offset_x < roll_grid[y].size() &&
                            offset_y >= 0 && offset_y < roll_grid.size())
                            if (roll_grid[offset_y][offset_x])
                                surrounding_rolls++;
                    }

                    if (surrounding_rolls < max_surrounding_rolls)
                    {
                        accessible_rolls++;
                        roll_grid[y][x] = false;
                    }
                }
            }
            cout << "ROW " << y << ": " << accessible_rolls << " ROLLS\n";
            rolls_accessed += accessible_rolls;
        }
        cout << "THIS ROUND REMOVED: " << rolls_accessed << endl;
        total_accessible_rolls += rolls_accessed;
    } 
    while (rolls_accessed != 0);

    cout << "TOTAL ROLLS: " << total_accessible_rolls << endl;


    cout << "----------------" << endl;
}