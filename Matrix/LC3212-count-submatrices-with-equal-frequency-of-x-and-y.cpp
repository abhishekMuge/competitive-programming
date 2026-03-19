#include <bits/std++.h>

using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Track running counts for X and Y
        vector<vector<int>> xCount(m, vector<int>(n, 0));
        vector<vector<int>> yCount(m, vector<int>(n, 0));
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Count X and Y in current cell
                xCount[i][j] = (grid[i][j] == 'X') ? 1 : 0;
                yCount[i][j] = (grid[i][j] == 'Y') ? 1 : 0;
                
                // Add from above
                if (i > 0) {
                    xCount[i][j] += xCount[i-1][j];
                    yCount[i][j] += yCount[i-1][j];
                }
                
                // Add from left
                if (j > 0) {
                    xCount[i][j] += xCount[i][j-1];
                    yCount[i][j] += yCount[i][j-1];
                }
                
                // Subtract overlapping part (added twice)
                if (i > 0 && j > 0) {
                    xCount[i][j] -= xCount[i-1][j-1];
                    yCount[i][j] -= yCount[i-1][j-1];
                }
                
                // Check conditions
                if (xCount[i][j] == yCount[i][j] && xCount[i][j] > 0) {
                    result++;
                }
            }
        }
        
        return result;
    }
};