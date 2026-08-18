class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> subarray_count;

        // Slide over all possible subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            // Collect unique elements in current subarray
            std::unordered_set<int> unique_in_subarray(nums.begin() + i, nums.begin() + i + k);
            
            // Increment the count for each unique element
            for (int num : unique_in_subarray) {
                subarray_count[num]++;
            }
        }

        int max_almost_missing = -1;

        // Find the maximum key with count == 1
        for (const auto& [num, count] : subarray_count) {
            if (count == 1) {
                max_almost_missing = std::max(max_almost_missing, num);
            }
        }

        return max_almost_missing;
    }
};


///another approach

#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int largestAlmostMissing(std::vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == n -> Entire array is the only subarray
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }

        // Count overall frequencies of elements in nums
        std::unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Case 2: k == 1 -> Find max element with total frequency of 1
        if (k == 1) {
            int max_val = -1;
            for (const auto& [num, count] : freq) {
                if (count == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }

        // Case 3: 1 < k < n -> Only nums[0] and nums[n-1] can appear in 1 subarray
        int ans = -1;
        if (freq[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (freq[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }

        return ans;
    }
};