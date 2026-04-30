#include <bits/stdc++.h>

using namespace std;

class solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 'o') return;

        grid[r][c] = 's';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    void solve(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }

        for(int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'o') {
                    grid[i][j] = 'x';
                } else if (grid[i][j] == 's')
                {
                    grid[i][j] = 'o';
                }
            }
        }
    }
};

