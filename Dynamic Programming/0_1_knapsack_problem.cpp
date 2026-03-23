#include <bits/stdc++.h>

using namespace std;
int memo[1001][1001];
int knapsack(int weights[], int values[], int capacity, int n) {
    //base cond
    if(n == 0 || weights == 0) {
        return 0;
    }

    //check if we have alredy know this state
    if(memo[n][capacity] != -1) {
        return memo[n][capacity];
    }

    if(weights[n-1] > capacity ) {
        return memo[n][capacity] = knapsack(weights, values, capacity, n -1);
    }
    else {
        int include = values[n-1] + knapsack(weights, values, capacity - weights[n-1], n-1);
        int exclude = knapsack(weights, values, capacity, n - 1);
        return memo[n][capacity] = max(include, exclude);
    }
}   


int knapsnackBottomUp(int w, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(w+1));

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            //base cond
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            else if(wt[i-1] <= w) {
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}