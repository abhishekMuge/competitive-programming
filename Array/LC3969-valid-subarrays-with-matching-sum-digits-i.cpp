#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isValid(long long sum, int x) {
        // Condition 1: Check last digit
        if (sum % 10 != x) return false;
        
        // Condition 2: Check first digit
        while (sum >= 10) {
            sum /= 10;
        }
        
        return sum == x;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int count = 0;

        std::vector<long long> prefixSum(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                long long currsum = prefixSum[r+1] - prefixSum[l];

                if (isValid(currsum, x)) {
                    count++;
                }
            }
        }

        return count;
    }
};
