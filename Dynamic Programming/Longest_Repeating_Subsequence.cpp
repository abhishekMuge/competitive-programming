#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int longestRepeatingSubsequence(std::string s) {
    int n = s.length();
    // Create a 2D DP table initialized to 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Check the 'Twist': values match but indices are different
            if (s[i - 1] == s[j - 1] && i != j) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}