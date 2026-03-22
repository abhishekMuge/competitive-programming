#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // Check all 4 rotations
        for (int k = 0; k < 4; k++) {
            if (mat == target) {
                return true;
            }
            rotate90(mat);
        }
        
        return false;
    }
    void rotate90(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};