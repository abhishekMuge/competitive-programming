#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        // Step 1: Use std::map to prevent anti-hash TLE test cases
        std::map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_len = 0;

        // Step 2: Handle the special case of 1
        if (freq.count(1)) {
            int count1 = freq[1];
            if (count1 % 2 == 0) {
                max_len = count1 - 1;
            } else {
                max_len = count1;
            }
        }

        // Step 3: Iterate through each unique number > 1
        for (auto& [key, value] : freq) {
            if (key == 1) continue;

            long long current_num = key;
            int current_len = 0;

            // This loop runs at most 5 times per key (O(log log M))
            while (freq.count(current_num)) {
                if (freq[current_num] >= 2) {
                    current_len += 2; 
                    
                    if (current_num > 100000) { 
                        break; 
                    }
                    current_num = current_num * current_num;
                } else if (freq[current_num] == 1) {
                    current_len += 1; 
                    break;            
                }
            }

            if (current_len > 0 && current_len % 2 == 0) {
                current_len -= 1;
            }

            max_len = std::max(max_len, current_len);
        }

        return max_len == 0 ? 1 : max_len;
    }
};