#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> mp;

        for(int i : nums1) {
            for(int j : nums2) {
                mp[i+j]++;
            }
        }
        int count = 0;
        for(int k: nums3) {
            for(int l: nums4) {
                int target = -(k +l);
                count += mp[target];
            }
        }
        return count;
    }
};