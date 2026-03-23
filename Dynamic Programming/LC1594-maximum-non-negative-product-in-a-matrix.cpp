#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;
        
        // DP arrays to store max and min products
        vector<vector<long long>> maxProd(m, vector<long long>(n));
        vector<vector<long long>> minProd(m, vector<long long>(n));
        
        // Initialize starting cell
        maxProd[0][0] = minProd[0][0] = grid[0][0];
        
        // Initialize first row
        for (int j = 1; j < n; j++) {
            maxProd[0][j] = minProd[0][j] = maxProd[0][j-1] * grid[0][j];
        }
        
        // Initialize first column
        for (int i = 1; i < m; i++) {
            maxProd[i][0] = minProd[i][0] = maxProd[i-1][0] * grid[i][0];
        }
        
        // Fill DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // For each cell, consider paths from above and left
                long long fromAboveMax = maxProd[i-1][j] * grid[i][j];
                long long fromAboveMin = minProd[i-1][j] * grid[i][j];
                long long fromLeftMax = maxProd[i][j-1] * grid[i][j];
                long long fromLeftMin = minProd[i][j-1] * grid[i][j];
                
                // Current cell's max and min are the extremes among all possibilities
                maxProd[i][j] = max({fromAboveMax, fromAboveMin, 
                                    fromLeftMax, fromLeftMin});
                minProd[i][j] = min({fromAboveMax, fromAboveMin, 
                                    fromLeftMax, fromLeftMin});
            }
        }
        
        // Check if we can get a non-negative product
        long long result = maxProd[m-1][n-1];
        if (result < 0) return -1;
        
        return result % MOD;
    }
};