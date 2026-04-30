#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dir) {
            int nr = r + d.first;
            int nc = c + d.second;

            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(heights, nr, nc, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, atlantic);
        }

        // Result
        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};