#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minInsertions(std::string s) {
        std::string r = s;
        std::reverse(r.begin(), r.end());
        int n = s.length();
        
        // Standard LCS logic
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == r[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // LPS is dp[n][n]
        return n - dp[n][n];
    }
};