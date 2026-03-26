#include <bits/stdc++.h>

using namespace std;

int minSubsetSumDifference(std::vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int x : nums) totalSum += x;

    int target = totalSum / 2;
    
    // dp[n+1][target+1]
    // dp[i][j] means: Is sum 'j' possible using a subset of first 'i' elements?
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base Case: Sum 0 is always possible with an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            // Case 1: Exclude the current element nums[i-1]
            // We just take the result from the previous row (same sum)
            dp[i][j] = dp[i - 1][j];

            // Case 2: Include the current element nums[i-1]
            // Only possible if the current element is not larger than the sum 'j'
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    // The last row (dp[n]) contains all possible sums using all elements
    // We look for the largest 'j' that is true in the last row
    int s1 = 0;
    for (int j = target; j >= 0; j--) {
        if (dp[n][j]) {
            s1 = j;
            break;
        }
    }

    return totalSum - 2 * s1;
}