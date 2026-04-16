#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n ; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(int q: queries) {
            vector<int>& idxs = mp[nums[q]];

            if(idxs.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int pos = lower_bound(idxs.begin(), idxs.end(), q) - idxs.begin();
            int res = INT_MAX;

            //left
            int left = idxs[(pos - 1 + idxs.size()) % idxs.size()];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

            //right 
            int right = idxs[(pos + 1) % idxs.size()];
            int d2 = abs(q- right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }
        return ans;
    }
};