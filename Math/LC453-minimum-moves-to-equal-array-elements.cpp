#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        long long n = nums.size();
        
        // Find the minimum element
        long long min_val = *std::min_element(nums.begin(), nums.end());
        
        // Calculate the total sum of all elements
        long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        
        // Apply the formula: moves = sum - (n * min)
        long long moves = total_sum - (n * min_val);
        
        return static_cast<int>(moves);
    }
};