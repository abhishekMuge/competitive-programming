#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // dp[i] will store all valid strings with i pairs
        vector<vector<string>> dp(n + 1);
        
        // Base case: 0 pairs is an empty string
        dp[0] = {""};
        
        // Build up from 1 pair to n pairs
        for (int i = 1; i <= n; ++i) {
            // To form i pairs, we use 1 pair as a 'wrapper' ( ... )
            // We have i - 1 pairs left to distribute
            for (int j = 0; j < i; ++j) {
                // j pairs go INSIDE the wrapper: ( dp[j] )
                // i - 1 - j pairs go OUTSIDE the wrapper: ( dp[j] ) dp[i-1-j]
                
                for (const string& inside : dp[j]) {
                    for (const string& outside : dp[i - 1 - j]) {
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }
        
        return dp[n];
    }
};