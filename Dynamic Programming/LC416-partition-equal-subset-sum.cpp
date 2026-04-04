#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        // If total sum is odd, can't partition equally
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        // dp[i][sum] = true if we can achieve 'sum' using first i elements
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base case: first element
        if (arr[0] <= target) dp[0][arr[0]] = true;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                bool notTake = dp[i - 1][sum];
                bool take = false;
                if (arr[i] <= sum)
                    take = dp[i - 1][sum - arr[i]];
                dp[i][sum] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
    bool canPartition(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        // We only need a 1D array of size target + 1
        vector<bool> dp(target + 1, false);
        
        dp[0] = true; // Base case: sum 0 is always possible

        for (int num : arr) {
            // Iterate backwards to prevent using the same element twice
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};