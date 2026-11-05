#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;

        for(int x: arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), (long long)x-d);

            if(it == arr2.end() || (long long)*it > (long long)x+d) {
                count++;
            }
        }
        return count;
    }
};