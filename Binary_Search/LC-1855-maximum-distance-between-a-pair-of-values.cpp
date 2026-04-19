#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = -1;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        for(int i = 0; i < n1; i++) {
            int left = i;
            int right = n2 - 1;
            int bestJ = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(nums2[mid] >= nums1[i]) {
                    bestJ = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (bestJ != -1) {
                maxDist = max(maxDist, bestJ - i);
            }
        }
        return maxDist;
    }
};

//Two Pointer Approach
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist = 0;
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            // Condition 1: i <= j (Implicitly handled)
            // Condition 2: nums1[i] <= nums2[j]
            if (nums1[i] <= nums2[j]) {
                maxDist = max(maxDist, j - i);
                j++; // Try to extend the distance by moving j
            } else {
                i++; // Current pair invalid, make nums1[i] smaller
            }
            
            // To ensure j >= i, we can sync j if i ever overtakes it
            if (j < i) {
                j = i;
            }
        }

        return maxDist;
    }
};