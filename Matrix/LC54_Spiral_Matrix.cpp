#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;

        if (matrix.empty() || matrix[0].size() < 1)
            return result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // tranverse top row
            for (int col = left; col <= right; col++)
            {
                result.push_back(matrix[top][col]);
            }
            top++;

            // traverse right column
            for (int row = top; row <= bottom; row++)
            {
                result.push_back(matrix[row][right]);
            }
            right--;

            // traverse bottom row from right -> left
            if (top <= bottom)
            {
                for (int col = right; col >= left; col--)
                {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int row = bottom; row >= top; row--)
                {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        return result;
    }
};