#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(std::string s, std::string t) {
    int n = s.length();
    int m = t.length();
    
    // dp[i][j] means s[0...i-1] is a subsequence of t[0...j-1]
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
    
    // Base case: empty s is a subsequence of any t
    for (int j = 0; j <= m; j++) {
        dp[0][j] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                // Characters match, move both pointers back
                dp[i][j] = dp[i-1][j-1];
            } else {
                // No match, check if s prefix was a subsequence of a shorter t
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
}bool isSubsequence(std::string s, std::string t) {
    int n = s.length();
    int m = t.length();
    
    // dp[i][j] means s[0...i-1] is a subsequence of t[0...j-1]
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
    
    // Base case: empty s is a subsequence of any t
    for (int j = 0; j <= m; j++) {
        dp[0][j] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                // Characters match, move both pointers back
                dp[i][j] = dp[i-1][j-1];
            } else {
                // No match, check if s prefix was a subsequence of a shorter t
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
}


bool isSubsequencePointer(std::string s, std::string t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.length();
}

