/*
Given two strings s1 and s2, find the length of the longest subsequence present in both of them.

Example:

s1 = "abcde", s2 = "ace"

The LCS is "ace", so the length is 3.

s1 = "abc", s2 = "def"

There are no common characters, so the length is 0
*/

#include <bits/stdc++.h>

using namespace std;

int RecursiveSolved(string s1, string s2, int i, int j) {
    // Base Case: If either string is exhausted
    if (i < 0 || j < 0) return 0;

    // Match
    if (s1[i] == s2[j]) {
        return 1 + RecursiveSolved(s1, s2, i - 1, j - 1);
    }

    // No Match
    return max(RecursiveSolved(s1, s2, i - 1, j), RecursiveSolved(s1, s2, i, j - 1));
}


class Solution {
    int memo[1001][1001]; // Adjust size based on constraints

    int solve(string& s1, string& s2, int i, int j) {
        if (i < 0 || j < 0) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) {
            return memo[i][j] = 1 + solve(s1, s2, i - 1, j - 1);
        }

        return memo[i][j] = max(solve(s1, s2, i - 1, j), solve(s1, s2, i, j - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(memo, -1, sizeof(memo));
        return solve(text1, text2, text1.size() - 1, text2.size() - 1);
    }
};

//Top down approach conversion  
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    
    // dp[n+1][m+1] initialized to 0
    // dp[i][j] stores LCS of s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If characters match, take diagonal + 1
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // If no match, take max of top or left cell
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The answer is in the bottom-right cell
    return dp[n][m];
}