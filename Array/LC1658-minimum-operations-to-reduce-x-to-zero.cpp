#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s = accumulate(nums.begin(), nums.end(), 0) - x;

        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int curr = 0;


        while(right < nums.size()) {
            curr += nums[right];

            while(curr > s && left <= right) {
                curr -= nums[left];
                left++;
            }

            if(curr == s) {
                ans = min(ans, static_cast<int>(
                    nums.size() - (right - left + 1)
                ));

            }
            right++;
        }
        return ans != INT_MAX ? ans : -1;

    }
};