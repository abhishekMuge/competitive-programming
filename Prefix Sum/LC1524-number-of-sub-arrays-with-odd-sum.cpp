#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long MOD = 1e9 + 7;
        long long odd_count = 0;
        long long even_count = 1; // Base case: prefix sum of 0 is even
        long long current_prefix_sum = 0;
        long long total_odd_subarrays = 0;
        
        for (int num : arr) {
            current_prefix_sum += num;
            
            if (current_prefix_sum % 2 == 1) {
                total_odd_subarrays = (total_odd_subarrays + even_count) % MOD;
                odd_count++;
            } else {
                total_odd_subarrays = (total_odd_subarrays + odd_count) % MOD;
                even_count++;
            }
        }
        
        return total_odd_subarrays;
    }
};