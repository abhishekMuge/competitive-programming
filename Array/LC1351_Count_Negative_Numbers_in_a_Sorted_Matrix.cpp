class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int r = m - 1; // Start at the last row
        int c = 0;     // Start at the first column
        int count = 0;

        // Starting from Bottom-Left corner
        while (r >= 0 && c < n)
        {
            if (grid[r][c] < 0)
            {
                // If this is negative, all elements to the right are negative
                count += (n - c);
                // Move up to check the previous row
                r--;
            }
            else
            {
                // If this is positive/zero, move right to find the negative boundary
                c++;
            }
        }

        return count;
    }
};