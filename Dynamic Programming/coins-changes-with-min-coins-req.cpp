#include <vector>
#include <algorithm>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    int INF = 1e9; // Represents infinity
    
    // dp[coin_index + 1][amount + 1]
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    // Base Case: Amount 0 always requires 0 coins
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            // Choice 1: Skip the current coin
            int notTake = dp[i - 1][j];

            // Choice 2: Use the current coin (if it fits in the remaining amount)
            int take = INF;
            if (coins[i - 1] <= j) {
                // Stay on row 'i' to allow infinite reuse of the same coin
                take = 1 + dp[i][j - coins[i - 1]];
            }

            dp[i][j] = min(take, notTake);
        }
    }

    // If the target amount is still INF, it means it's impossible to form
    return (dp[n][amount] >= INF) ? -1 : dp[n][amount];
}