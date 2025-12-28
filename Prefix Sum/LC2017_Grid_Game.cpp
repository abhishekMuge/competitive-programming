#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        long long top_row_rem = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottom_row_sum = 0;

        long long min_robot2_points = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            top_row_rem -= grid[0][i];

            long long robot2_choice = max(top_row_rem, bottom_row_sum);
            min_robot2_points = min(min_robot2_points, robot2_choice);

            bottom_row_sum += grid[1][i];
        }
        return min_robot2_points;
    }
};