#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i < m; i++) {
            for(int j = n; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};

//Bottom Up approach

int numDistinct(std::string s, std::string t) {
    int m = s.length();
    int n = t.length();

    std::vector<std::vector<unsigned long long>> dp(m + 1, std::vector<unsigned long long>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 1;
    }


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                // Choice 1: Use s[i-1] to match t[j-1] -> dp[i-1][j-1]
                // Choice 2: Skip s[i-1] -> dp[i-1][j]
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                // Must skip s[i-1] because characters don't match
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[m][n];
}