#include <bits/stdc++.h>

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int rows = strs.size();
        int cols = strs[0].size();

        // resolved[i] = true means strs[i] < strs[i+1] is already decided
        vector<bool> resolved(rows - 1, false);

        int deletions = 0;

        // Process columns from left to right
        for (int c = 0; c < cols; ++c)
        {

            // Step 1: Check if this column causes any violation
            bool deleteColumn = false;

            for (int i = 0; i < rows - 1; ++i)
            {
                if (!resolved[i] && strs[i][c] > strs[i + 1][c])
                {
                    deleteColumn = true;
                    break;
                }
            }

            // If violation exists, delete this column
            if (deleteColumn)
            {
                deletions++;
                continue;
            }

            // Step 2: Use this column to resolve ordering where possible
            for (int i = 0; i < rows - 1; ++i)
            {
                if (!resolved[i] && strs[i][c] < strs[i + 1][c])
                {
                    resolved[i] = true;
                }
            }

            // Optional optimization: if all pairs are resolved, we can stop
            bool allResolved = true;
            for (bool r : resolved)
            {
                if (!r)
                {
                    allResolved = false;
                    break;
                }
            }
            if (allResolved)
                break;
        }

        return deletions;
    }
};
