#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int>& price, int n) {
    // dp[piece_types][total_length]
    // We use n+1 to account for 0 length and pieces up to length n
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Option 1: Don't use a piece of length 'i'
            // Just take the best result from the previous pieces
            int notTake = dp[i - 1][j];

            // Option 2: Use a piece of length 'i'
            int take = 0;
            if (i <= j) {
                // IMPORTANT: We look at dp[i][j - i], NOT dp[i - 1][j - i]
                // This allows for multiple cuts of the same length 'i'
                take = price[i - 1] + dp[i][j - i];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n][n];
}

int rodCuttingGeneral(vector<int>& length, vector<int>& price, int n) {
    int m = length.size(); // Number of piece types available
    
    // dp[piece_index][current_rod_length]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            
            // Option 1: Don't use the i-th piece type
            int notTake = dp[i - 1][j];

            // Option 2: Use the i-th piece type
            int take = 0;
            if (length[i - 1] <= j) {
                // IMPORTANT: We look at dp[i][j - length[i-1]] 
                // We stay in the SAME ROW (i) to allow multiple cuts of this length
                take = price[i - 1] + dp[i][j - length[i - 1]];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[m][n];
}