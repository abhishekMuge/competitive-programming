#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;

        // Step 1: Compute total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        // If total sum is odd → cannot split
        if (totalSum % 2 != 0) return false;

        long long target = totalSum / 2;

        // -------------------------
        // Step 2: Check vertical cut
        // -------------------------
        vector<long long> colSum(n, 0);

        // Precompute column sums
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colSum[j] += grid[i][j];
            }
        }

        long long curr = 0;
        for (int j = 0; j < n - 1; j++) { // ensure both parts non-empty
            curr += colSum[j];
            if (curr == target) return true;
        }

        // -------------------------
        // Step 3: Check horizontal cut
        // -------------------------
        vector<long long> rowSum(m, 0);

        // Precompute row sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
            }
        }

        curr = 0;
        for (int i = 0; i < m - 1; i++) { // ensure both parts non-empty
            curr += rowSum[i];
            if (curr == target) return true;
        }

        return false;
    }
};