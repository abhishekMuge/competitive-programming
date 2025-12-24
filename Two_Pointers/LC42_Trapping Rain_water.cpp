class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> leftMax(n), rightMax(n);
        int res = 0;

        // Fill leftMax
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Fill rightMax
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate trapped water
        for (int i = 0; i < n; i++)
        {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
};

/*Updated Two-Pointer approach*/

#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {

        // Edge case: less than 3 bars cannot trap any water
        if (height.size() < 3)
            return 0;

        // Two pointers starting from both ends
        int left = 0;
        int right = height.size() - 1;

        // Track the maximum height encountered so far from both sides
        int leftMax = 0;
        int rightMax = 0;

        // Total water trapped
        int totalWater = 0;

        // Process bars until pointers meet
        while (left < right)
        {

            // Always process the side with smaller height
            // because water level is limited by the smaller boundary
            if (height[left] <= height[right])
            {

                // If current bar is taller than previous max,
                // update leftMax (no water trapped here)
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                // Otherwise, water can be trapped
                // Difference between leftMax and current height
                else
                {
                    totalWater += leftMax - height[left];
                }

                // Move left pointer inward
                left++;
            }
            else
            {
                // Symmetric logic for the right side

                // Update rightMax if current bar is taller
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                // Otherwise, trap water at this position
                else
                {
                    totalWater += rightMax - height[right];
                }

                // Move right pointer inward
                right--;
            }
        }

        return totalWater;
    }
};
