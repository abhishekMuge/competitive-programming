#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Prefix sums
        vector<vector<int>> rowPref(m, vector<int>(n + 1, 0));
        vector<vector<int>> colPref(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag1(m, vector<int>(n, 0)); // ↘
        vector<vector<int>> diag2(m, vector<int>(n, 0)); // ↙

        // Build row & column prefix sums
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                rowPref[r][c + 1] = rowPref[r][c] + grid[r][c];
                colPref[r + 1][c] = colPref[r][c] + grid[r][c];

                diag1[r][c] = grid[r][c] + (r > 0 && c > 0 ? diag1[r - 1][c - 1] : 0);
                diag2[r][c] = grid[r][c] + (r > 0 && c + 1 < n ? diag2[r - 1][c + 1] : 0);
            }
        }

        int maxK = min(m, n);

        // Try largest size first
        for (int k = maxK; k >= 2; k--)
        {
            for (int r = 0; r + k <= m; r++)
            {
                for (int c = 0; c + k <= n; c++)
                {

                    // Target sum = first row
                    int target = rowPref[r][c + k] - rowPref[r][c];

                    bool valid = true;

                    // Check all rows
                    for (int i = 0; i < k && valid; i++)
                    {
                        int sumRow = rowPref[r + i][c + k] - rowPref[r + i][c];
                        if (sumRow != target)
                            valid = false;
                    }

                    // Check all columns
                    for (int j = 0; j < k && valid; j++)
                    {
                        int sumCol = colPref[r + k][c + j] - colPref[r][c + j];
                        if (sumCol != target)
                            valid = false;
                    }

                    // Check main diagonal
                    int mainDiag =
                        diag1[r + k - 1][c + k - 1] -
                        (r > 0 && c > 0 ? diag1[r - 1][c - 1] : 0);

                    if (mainDiag != target)
                        valid = false;

                    // Check anti-diagonal
                    int antiDiag =
                        diag2[r + k - 1][c] -
                        (r > 0 && c + k < n ? diag2[r - 1][c + k] : 0);

                    if (antiDiag != target)
                        valid = false;

                    if (valid)
                        return k;
                }
            }
        }

        // Every 1x1 grid is magic
        return 1;
    }
};
