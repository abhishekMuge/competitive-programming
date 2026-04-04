#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = totalSum / 2;

        // Create a 2D table: rows = stones, cols = target + 1
        // Initialize everything to false
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base Case: A sum of 0 is always possible (by picking no stones)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base Case: The first stone can form its own weight (if it fits)
        if (stones[0] <= target) {
            dp[0][stones[0]] = true;
        }

        // Fill the table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                // Option 1: Don't include the current stone
                bool notTake = dp[i - 1][j];

                // Option 2: Include the current stone (if its weight <= current j)
                bool take = false;
                if (stones[i] <= j) {
                    take = dp[i - 1][j - stones[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        // Find the largest 'j' that is true in the last row
        int maxSubsetSum = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[n - 1][j]) {
                maxSubsetSum = j;
                break; 
            }
        }

        // The answer is the difference: (Total - maxSubsetSum) - maxSubsetSum
        return totalSum - 2 * maxSubsetSum;
    }
};