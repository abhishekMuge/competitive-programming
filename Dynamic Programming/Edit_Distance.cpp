#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Base cases: filling first row and first column
        for (int i = 0; i <= m; i++) dp[i][0] = i; // Deletions
        for (int j = 0; j <= n; j++) dp[0][j] = j; // Insertions
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // No operation needed
                } else {
                    // Min of Replace, Delete, Insert
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                }
            }
        }
        
        return dp[m][n];
    }
};