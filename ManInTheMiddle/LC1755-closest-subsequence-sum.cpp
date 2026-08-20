#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        int n1 = n /2;
        int n2 = n - n1;

        vector<int> sumA(1LL << n1);

        for(int mask = 0; mask < (1 << n1); mask++) {
            int s = 0;

            for(int i = 0; i < n1; i++) {
                if(mask && (1 << i)) s += nums[i];
            }
            sumA[mask] = s;
        }



        vector<int> sumB(1LL << n2);

        for(int mask = 0; mask < (1 << n2); mask++) {
            int s = 0;

            for(int i = 0; i < n2; i++) {
                if(mask && (1 << i)) s += nums[n1 + i];
            }
            sumB[mask] = s;
        }

        sort(begin(sumB), end(sumB));

        int minValue = INT_MAX;
        for (int sum1 : sumA) {
            int need = goal - sum1;
            int low  = lower_bound(begin(sumB), end(sumB), need) - begin(sumB);

            if (low < sumB.size()) {
                int sum2 = sumB[low];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(total - goal));
            }

            if (low > 0) {
                int sum2 = sumB[low-1];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(total - goal));
            }
        }
        return minValue;
    }
};