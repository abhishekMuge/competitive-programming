#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        auto min_it = min_element(nums.begin(), nums.end());
        auto max_it = max_element(nums.begin(), nums.end());

        return gcd(*min_it, *max_it);
    }
};