#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    // Use a large value for infinity, but small enough to avoid overflow
    int INF = 1e9; 
    
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    // Base case: 0 amount needs 0 coins
    for (int i = 0; i <= n; i++) dp[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            // Option 1: Don't use the current coin
            int notTake = dp[i - 1][j];

            // Option 2: Use the current coin
            int take = INF;
            if (coins[i - 1] <= j) {
                // Stay on current row 'i' to allow infinite reuse
                take = 1 + dp[i][j - coins[i - 1]];
            }

            dp[i][j] = min(take, notTake);
        }
    }

    return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
}