#include<bits/stdc++.h>

using namespace std;

// Function to print the matrix with clear formatting
void printMatrix(const vector<vector<int>>& mat, string label) {
    cout << "--- " << label << " ---" << endl;
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
/*
Current complexity:
O(M∗N) - Time
O(M∗N) - Space
*/
void rotateBoundary(vector<vector<int>>& mat, int k) {
	int m = mat.size();
	int n = mat[0].size();

	int numLayers = min(m, n) / 2;

	for(int layer = 0; layer < numLayers; layer++) {
		vector<int> boundary;

		int top = layer;
		int bottom = (m - 1 - layer);
		int left = layer;
		int right = (n - 1 - layer);

		//1. Extract current boundary
		for(int j = left; j <= right; j++) boundary.push_back(mat[top][j]);

		for(int j = top+1; j <= bottom; j++) boundary.push_back(mat[j][right]);

		for(int j = right-1; j >= left; j--) boundary.push_back(mat[bottom][j]);

		for(int j = bottom - 1; j > top; j--) boundary.push_back(mat[j][left]);

		int len = boundary.size();
		if (len == 0) continue;
		int shift = k % len;
		rotate(boundary.begin(), boundary.begin() + shift, boundary.end());

		// 3. Put elements back
		int idx = 0;
		for (int j = left; j <= right; j++) mat[top][j] = boundary[idx++];
		for (int i = top + 1; i <= bottom; i++) mat[i][right] = boundary[idx++];
		for (int j = right - 1; j >= left; j--) mat[bottom][j] = boundary[idx++];
		for (int i = bottom - 1; i > top; i--) mat[i][left] = boundary[idx++];
	}
}

int main() {
    // Example: 4x4 matrix
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    printMatrix(matrix, "Original Matrix");

    // Rotate boundary by 1 position clockwise
    rotateBoundary(matrix, 1);

    printMatrix(matrix, "After 1-Step Clockwise Boundary Rotation");

    return 0;
}
