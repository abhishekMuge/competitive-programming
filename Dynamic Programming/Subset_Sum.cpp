#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solvedSumSetSum(const vector<int>& nums, int n, int target) {
        std::vector<std::vector<bool>> dp (n + 1, vector<bool>(target + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int j = 1; j <= target; j++)
            dp[0][j] = false;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                if(j < nums[i-1]) // if current element at (i-1) is greater than target sum j then we can not used that
                {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    //check if we obtain j=target by excluding or including current element
                    dp[i][j] = dp[i -1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};