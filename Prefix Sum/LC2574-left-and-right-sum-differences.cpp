#include <vector>
#include <numeric> // For std::accumulate
#include <cmath>   // For std::abs

class Solution {
public:
    std::vector<int> leftRightDifference(std::vector<int>& nums) {
        int n = nums.size();
        
        // 1. Find the total sum of the array
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        
        int left_sum = 0;
        std::vector<int> answer(n);
        
        // 2. Calculate the absolute differences on the fly
        for (int i = 0; i < n; ++i) {
            // right_sum is total_sum minus left_sum minus the current element
            int right_sum = total_sum - left_sum - nums[i];
            
            // Store the absolute difference
            answer[i] = std::abs(left_sum - right_sum);
            
            // Move the current element to the left_sum for the next index
            left_sum += nums[i];
        }
        
        return answer;
    }
};