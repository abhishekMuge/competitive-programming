#include <bits/std++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Result matrix of size (m - k + 1) x (n - k + 1)
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));
        
        // For each possible top-left corner of k x k submatrix
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                // Use a set to get distinct values in current submatrix
                set<int> distinctValues;
                
                // Collect all elements in the current k x k submatrix
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        distinctValues.insert(grid[x][y]);
                    }
                }
                
                // If only one distinct value, answer is 0
                if (distinctValues.size() == 1) {
                    result[i][j] = 0;
                    continue;
                }
                
                // Convert set to vector for easier processing
                vector<int> sortedValues(distinctValues.begin(), distinctValues.end());
                
                // Find minimum adjacent difference
                int minDiff = INT_MAX;
                for (size_t idx = 0; idx < sortedValues.size() - 1; idx++) {
                    int diff = sortedValues[idx + 1] - sortedValues[idx];
                    if (diff < minDiff) {
                        minDiff = diff;
                    }
                }
                
                result[i][j] = minDiff;
            }
        }
        
        return result;
    }
};