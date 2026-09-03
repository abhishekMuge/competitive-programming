#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOld = INT_MAX;

        for(int num: nums1) {
            if(num % 2 != 0) minOld = std::min(minOld, num);
        }

        if(minOld == INT_MAX) return true;

        for(int n : nums1) {
            if(n % 2 == 0 && n < minOld) return false;
        }
        return true;
    }
};