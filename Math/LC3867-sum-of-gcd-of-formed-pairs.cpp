#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefix;

        int mx = 0;

        for (int x : nums) {
            mx = max(mx, x);
            prefix.push_back(std::gcd(x, mx));
        }

        sort(prefix.begin(), prefix.end());

        long long ans = 0;

        int l = 0;
        int r = prefix.size() - 1;

        while (l < r) {
            ans += gcd(prefix[l], prefix[r]);
            l++;
            r--;
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3, 6, 2, 8};

    Solution sol;

    cout << sol.gcdSum(nums) << endl;

    return 0;
}