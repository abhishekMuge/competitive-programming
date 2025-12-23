class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        long long count = 0;

        int badIndex = -1;
        int minIndex = -1;
        int maxIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                badIndex = i;
                continue;
            }
            if (nums[i] == minK)
                minIndex = i;

            if (nums[i] == maxK)
                maxIndex = i;

            if (minIndex != -1 && maxIndex != -1)
            {
                int leftBoundary = min(minIndex, maxIndex);
                // Leftboundary has to be greater to get the effect of adding count.
                // if BadIndex is greater than min(MinIDX, maxIdx) -> count will have zero.
                if (leftBoundary > badIndex)
                {
                    count += (leftBoundary - badIndex);
                }
            }
        }
        return count;
    }
};