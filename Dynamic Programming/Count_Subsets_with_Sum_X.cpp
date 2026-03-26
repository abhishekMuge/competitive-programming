#include <bits/stdc++.h>

using namespace std;
#include <iostream>
#include <vector>

int countSubsets(std::vector<int>& nums, int X) {
    int n = nums.size();
    
    // dp[n+1][X+1] initialized to 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(X + 1, 0));

    // Base Case: There is 1 way to make sum 0 (the empty set)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            // Case 1: Exclude the current number nums[i-1]
            // The number of ways is at least what we had in the previous row
            dp[i][j] = dp[i - 1][j];

            // Case 2: Include the current number nums[i-1]
            // If the number is smaller than or equal to our current target sum 'j'
            if (j >= nums[i - 1]) {
                // Add the number of ways we could form (j - current_num) 
                // using the previous elements
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][X];
}
