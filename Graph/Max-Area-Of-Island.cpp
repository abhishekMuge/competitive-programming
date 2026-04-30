#include <bits/stdc++.h>

using namespace std;

class solution {
public:
    int m, n;

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) return 0;

        grid[r][c] = 0;

        return 1 +
                dfs(grid, r+1, c) + 
                dfs(grid, r-1, c) +
                dfs(grid, r, c+1) +
                dfs(grid, r, c-1);
    }

    int maxNoOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;    
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    int area = 0;

                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 0; // mark visited

                    while (!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();

                        area++;

                        for (auto& d : dir) {
                            int nr = r + d.first;
                            int nc = c + d.second;

                            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                                grid[nr][nc] == 1) {

                                grid[nr][nc] = 0;
                                q.push({nr,nc});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};