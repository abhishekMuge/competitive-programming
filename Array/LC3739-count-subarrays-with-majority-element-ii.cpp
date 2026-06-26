#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        std::unordered_map<int, int> counts;
        
        // Base case: before processing any element, prefix_sum is 0
        counts[0] = 1;
        
        int prefix_sum = 0;
        int smaller_counts = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            if (num == target) {
                // Prefix sum increases: gain the counts of the old prefix sum
                smaller_counts += counts[prefix_sum];
                prefix_sum += 1;
            } else {
                // Prefix sum decreases: lose the counts of the new prefix sum
                prefix_sum -= 1;
                smaller_counts -= counts[prefix_sum];
            }
            
            // Add the number of valid starting points to our total
            total_subarrays += smaller_counts;
            
            // Record the current prefix sum occurrence
            counts[prefix_sum]++;
        }
        
        return total_subarrays;
    }
};