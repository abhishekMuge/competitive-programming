#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int calc = 0;
        bool hasNonZero = false;
        for(int x: nums) {
            calc ^= x;
            if (x != 0) hasNonZero = true;
        }

        if(calc != 0) return nums.size();

        return hasNonZero ? (nums.size() -  1) : 0;
    }
};