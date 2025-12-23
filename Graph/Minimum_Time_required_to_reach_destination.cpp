#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool canReachInTime(vector<vector<int>> &matrix, int T)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int m = matrix.size();
    int n = matrix[0].size();

    // If start or end is blocked
    if (matrix[0][0] == 1 || matrix[m - 1][n - 1] == 1)
    {
        return false;
    }

    // Directions: right, down, left, up
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Visited matrix to avoid revisiting cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Queue for BFS: (row, col, time)
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [r, c, time] = q.front();
        q.pop();

        // If we reached the destination
        if (r == m - 1 && c == n - 1)
        {
            return time <= T;
        }

        // If time already exceeds T, skip expanding this path
        if (time > T)
        {
            continue;
        }

        // Explore neighbors
        for (auto [dr, dc] : directions)
        {
            int nr = r + dr;
            int nc = c + dc;

            // Check bounds, not blocked, and not visited
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                matrix[nr][nc] == 0 && !visited[nr][nc])
            {

                visited[nr][nc] = true;
                q.push({nr, nc, time + 1});
            }
        }
    }

    // Destination not reachable at all
    return false;
}

int main()
{
    // Example 1: Reachable within time
    vector<vector<int>> matrix1 = {
        {0, 0, 1},
        {1, 0, 0},
        {1, 1, 0}};
    int T1 = 4;
    cout << "Example 1: " << (canReachInTime(matrix1, T1) ? "Yes" : "No") << endl;

    // Example 2: Not reachable within time (blocked path)
    vector<vector<int>> matrix2 = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0}};
    int T2 = 10;
    cout << "Example 2: " << (canReachInTime(matrix2, T2) ? "Yes" : "No") << endl;

    // Example 3: Reachable exactly at minimum time
    vector<vector<int>> matrix3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    int T3 = 4; // Minimum path from (0,0) to (2,2) is 4 steps
    cout << "Example 3: " << (canReachInTime(matrix3, T3) ? "Yes" : "No") << endl;

    return 0;
}