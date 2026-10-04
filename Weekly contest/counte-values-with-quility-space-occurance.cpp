#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> hs;

        for(int i = 0; i < nums.size(); i++) {
            hs[nums[i]].push_back(i);
        }
        int spcnt = 0;
        for(const auto& [val, idx]: hs) {
            if(idx.size() == 3) {
                if(idx[1] - idx[0] == idx[2] - idx[1]) spcnt++;
            }
        }
        return spcnt;
    }
}