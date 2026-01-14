#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    // Helper function: Largest Rectangle in Histogram
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.push_back(0); // Sentinel to flush stack
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back(); // Restore input
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++)
        {
            // Build histogram for current row
            for (int c = 0; c < cols; c++)
            {
                if (matrix[r][c] == '1')
                    heights[c] += 1;
                else
                    heights[c] = 0;
            }

            // Find max rectangle for this histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};