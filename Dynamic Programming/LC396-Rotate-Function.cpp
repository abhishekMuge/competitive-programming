#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        long long sum = 0;
        long long F = 0;

        // Step 1: compute sum and F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long long)i * nums[i];
        }

        long long maxVal = F;

        // Step 2: use recurrence
        for (int k = 1; k < n; k++) {
            F = F + sum - (long long)n * nums[n - k];
            maxVal = max(maxVal, F);
        }

        return (int)maxVal;  // safe as per constraints
    }
};