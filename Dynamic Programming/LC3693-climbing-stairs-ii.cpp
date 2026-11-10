#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                int prev = i - j;

                if(prev >= 0) {
                    int cost = costs[i-1] + (j * j);

                    dp[i] = min(dp[i], dp[prev] + cost);
                }
            }
        }
        return dp[n];
    }
};