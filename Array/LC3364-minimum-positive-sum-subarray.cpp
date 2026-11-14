#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix_sum(n+1, 0);      

        for(int i = 0; i < n; i++) {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }

        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int len = l; len <= r; len++) {
                int j = i + len;
                if (j > n) break;

                int sum = prefix_sum[j] - prefix_sum[i];

                if(sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1: ans;
    }
};



class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        // Step 1: Build prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Maintain eligible prefix sums
        multiset<long long> window;

        long long ans = LLONG_MAX;

        // Step 3: Fix ending index
        for (int j = 1; j <= n; j++) {

            // Add newly eligible starting prefix
            if (j - l >= 0) {
                window.insert(prefix[j - l]);
            }

            // Remove prefix that creates length > r
            if (j - r - 1 >= 0) {
                auto it = window.find(prefix[j - r - 1]);

                if (it != window.end()) {
                    window.erase(it);
                }
            }

            // Step 4: Find largest prefix < current prefix
            auto it = window.lower_bound(prefix[j]);

            if (it != window.begin()) {
                --it;

                long long sum = prefix[j] - *it;

                ans = min(ans, sum);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
