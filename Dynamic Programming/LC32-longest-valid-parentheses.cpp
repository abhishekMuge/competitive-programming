#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // dp[i] stores the length of the longest valid substring ending at index i
        std::vector<int> dp(n, 0);
        int max_len = 0;
        
        // We start from index 1 because index 0 cannot form a pair
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // CASE A: Simple pair "()"
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                // CASE B: Nested pair "...))"
                // Check if there is a matching '(' before the current valid block
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    int inner_len = dp[i - 1];
                    int new_pair = 2;
                    // Check if there was a valid substring before the matching '('
                    int prev_len = (i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0;
                    
                    dp[i] = inner_len + new_pair + prev_len;
                }
                
                max_len = std::max(max_len, dp[i]);
            }
        }
        
        return max_len;
    }
};