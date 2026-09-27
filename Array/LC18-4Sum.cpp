#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.empty()){
            return res;
        }

        sort(nums.begin(), nums.end());

        long long fixedTarget = target;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            long long target3 = fixedTarget - nums[i];

            for(int j = i+1; j < nums.size(); j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                long long target2 = target3 - nums[j];

                int front = j+1;
                int back = nums.size() -1;

                while(front < back) {
                    long long sum2 = (long long)nums[front] + nums[back];

                    if(sum2 < target2) {
                        front++;
                    }
                    else if(sum2 > target2) {
                        back--;
                    }
                    else{
                        vector<int> qpoint = {nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(qpoint);

                        while(front < back && nums[front] == qpoint[2]) {
                            ++front;
                        }
                        while(back > front && nums[back] == qpoint[3]) {
                            --back;
                        }
                    }
                } 
            }
            return res;

        }

        

    }
};

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early pruning for loop i
            long long min1 = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min1 > target) break;

            long long max1 = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (max1 < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Early pruning for loop j
                long long min2 = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > target) break;

                long long max2 = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < target) continue;

                int front = j + 1;
                int back = n - 1;

                while (front < back) {
                    long long sum = (long long)nums[i] + nums[j] + nums[front] + nums[back];

                    if (sum < target) {
                        front++;
                    } else if (sum > target) {
                        back--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[front], nums[back]});

                        int leftVal = nums[front];
                        int rightVal = nums[back];

                        while (front < back && nums[front] == leftVal) front++;
                        while (front < back && nums[back] == rightVal) back--;
                    }
                }
            }
        }

        return res; // Returned after full traversal
    }
};