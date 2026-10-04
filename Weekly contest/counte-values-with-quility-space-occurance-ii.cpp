
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        std::unordered_map<int, std::vector<int>> hm;

        for(int i = 0; i < nums.size(); i++) {
            hm[nums[i]].push_back(i);
        }
        int spcnt =0;
        for(const auto& [val, idxmp]: hm) {
            int m = idxmp.size();
            if(m < 3) continue;
            int diff = idxmp[1] - idxmp[0];
            bool iseq = true;

            for(int j = 2; j < idxmp.size();  j++) {
                if(idxmp[j] - idxmp[j-1] != diff) {
                    iseq=false;
                    break;
                }
            }
            if(iseq) spcnt++;
        }
        return spcnt;
    }
};