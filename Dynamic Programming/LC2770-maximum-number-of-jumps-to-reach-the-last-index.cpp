#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& nums, int target, int n, vector<int>& memo) {
        if(i == n-1) return 0;
        if(memo[i] != -2) return memo[i];
        int best = -1; // not reachable

        for(int j = i+1; j < n; j++) {
            if(abs(nums[j] - nums[i]) <= target) {
                int jumpFromJ = solve(j, nums, target, n, memo);

                if(jumpFromJ != -1) {
                    best = max(best, 1 + jumpFromJ);
                }
            }
        }
        return memo[i] = best;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n, -2);
        return solve(0, nums, target, n, memo);
    }
};