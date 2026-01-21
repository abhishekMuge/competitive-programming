#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int current = 1;

        while (top <= bottom && left <= right)
        {
            // Fill top row
            for (int col = left; col <= right; col++)
            {
                matrix[top][col] = current++;
            }
            top++;

            // Fill right column
            for (int row = top; row <= bottom; row++)
            {
                matrix[row][right] = current++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom)
            {
                for (int col = right; col >= left; col--)
                {
                    matrix[bottom][col] = current++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right)
            {
                for (int row = bottom; row >= top; row--)
                {
                    matrix[row][left] = current++;
                }
                left++;
            }
        }

        return matrix;
    }
};
