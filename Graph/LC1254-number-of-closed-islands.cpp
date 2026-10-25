#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }

        grid[r][c] = 1;
        dfs(grid, r+1, c);
        dfs(grid, r-1,c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 1. Flood-fill all border-connected land
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c);
                }
            }
        }

        int closedIslands = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedIslands++;
                    dfs(grid, r, c); // Mark the entire island as visited
                }
            }
        }

        return closedIslands;
    }
};