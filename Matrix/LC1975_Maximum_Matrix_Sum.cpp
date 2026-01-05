#include <bits/stdc++.h>

using namesapce std;
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (auto &row : matrix)
        {
            for (int val : row)
            {
                totalSum += abs(val);
                if (val < 0)
                {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2 != 0)
        {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};
/*
below is the variation where we have to return the updated matrix with flip sign.
*/

class Solution
{
public:
    pair<long long, vector<vector<int>>> maxMatrixSumWithMatrix(
        vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        long long absSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;
        int minR = 0, minC = 0;

        // Step 1: Collect statistics
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int val = matrix[i][j];
                if (val < 0)
                    negCount++;
                int absVal = abs(val);
                absSum += absVal;

                if (absVal < minAbs)
                {
                    minAbs = absVal;
                    minR = i;
                    minC = j;
                }
            }
        }

        // Step 2: Make all elements positive
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = abs(matrix[i][j]);
            }
        }

        // Step 3: If odd negatives, force one minimum cell negative
        if (negCount % 2 == 1)
        {
            matrix[minR][minC] = -matrix[minR][minC];
            absSum -= 2LL * minAbs;
        }

        return {absSum, matrix};
    }
};
