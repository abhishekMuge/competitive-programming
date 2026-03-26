#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        // If total sum is odd, we cannot split it into two equal integer sums
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        
        // Now solve exactly like Subset Sum problem
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1));

        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int j = 1; j <= target; j++) dp[0][j] = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};