#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> diag1(m, vector<int>(n));
        vector<vector<int>> diag2(m, vector<int>(n));

        // build diag1 (\ direction)
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diag1[i][j] = grid[i][j];
                if(i>0 && j>0)
                    diag1[i][j] += diag1[i-1][j-1];
            }
        }

        // build diag2 (/ direction)
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                diag2[i][j] = grid[i][j];
                if(i>0 && j+1<n)
                    diag2[i][j] += diag2[i-1][j+1];
            }
        }

        set<int, greater<int>> sums;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){

                // size 0 rhombus
                sums.insert(grid[r][c]);

                int maxSize = min({r, m-1-r, c, n-1-c});

                for(int k=1;k<=maxSize;k++){

                    int top_r = r-k, top_c = c;
                    int right_r = r, right_c = c+k;
                    int bottom_r = r+k, bottom_c = c;
                    int left_r = r, left_c = c-k;

                    int sum = 0;

                    // top -> right
                    sum += diag1[right_r][right_c];
                    if(top_r-1>=0 && top_c-1>=0)
                        sum -= diag1[top_r-1][top_c-1];

                    // right -> bottom
                    sum += diag2[bottom_r][bottom_c];
                    if(right_r-1>=0 && right_c+1<n)
                        sum -= diag2[right_r-1][right_c+1];

                    // bottom -> left
                    sum += diag1[bottom_r][bottom_c];
                    if(left_r-1>=0 && left_c-1>=0)
                        sum -= diag1[left_r-1][left_c-1];

                    // left -> top
                    sum += diag2[left_r][left_c];
                    if(top_r-1>=0 && top_c+1<n)
                        sum -= diag2[top_r-1][top_c+1];

                    // remove corner duplicates
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    sums.insert(sum);
                }
            }
        }

        vector<int> ans;

        for(int x : sums){
            ans.push_back(x);
            if(ans.size()==3) break;
        }

        return ans;
    }
};