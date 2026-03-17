#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> height(m, vector<int>(n));

        // Step 1: build heights
        for(int j = 0; j < n; j++){
            height[0][j] = matrix[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1)
                    height[i][j] = height[i-1][j] + 1;
                else
                    height[i][j] = 0;
            }
        }

        int ans = 0;

        // Step 2: process each row
        for(int i = 0; i < m; i++){
            
            vector<int> curr = height[i];

            // sort descending
            sort(curr.begin(), curr.end(), greater<int>());

            // compute max area
            for(int j = 0; j < n; j++){
                int h = curr[j];
                int w = j + 1;
                ans = max(ans, h * w);
            }
        }

        return ans;
    }
};