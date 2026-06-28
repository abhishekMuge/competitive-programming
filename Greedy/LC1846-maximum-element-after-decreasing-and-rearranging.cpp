#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Set the first element to 1
        arr[0] = 1;
        
        // Step 3: Enforce the consecutive difference constraint
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > arr[i - 1] + 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        
        // The last element will contain the maximum possible value
        return arr.back();
    }
};