#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
    
        // dp[item_index][zeros_limit][ones_limit]
        // Initialized to 0
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= len; i++) {
            // Step 1: Count zeros and ones in the current string (i-1 because strs is 0-indexed)
            int z = 0, o = 0;
            for (char c : strs[i - 1]) {
                if (c == '0') z++;
                else o++;
            }

            // Step 2: Iterate through every possible budget of zeros and ones
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    
                    // Option 1: Don't take the current string
                    int notTake = dp[i - 1][j][k];
                    
                    // Option 2: Take the current string (if budget allows)
                    int take = 0;
                    if (j >= z && k >= o) {
                        take = 1 + dp[i - 1][j - z][k - o];
                    }
                    
                    // Pick the best of both worlds
                    dp[i][j][k] = max(take, notTake);
                }
            }
        }

        return dp[len][m][n];
    }
};