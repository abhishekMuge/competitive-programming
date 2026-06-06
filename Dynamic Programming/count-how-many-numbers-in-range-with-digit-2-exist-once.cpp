/*
concrete problem: Count how many numbers between 0 and 324 have the digit '2' exactly once
*/

#include<bits/stdc++.h>

using namespace std;
// dp[index][tight][count_of_twos]
int dp[20][2][20];

string num;

int solve(int idx, bool tight, int count) {
    if(idx == num.size()) {
        return count == 1;
    }

    if(dp[idx][tight][count] != -1) return dp[idx][tight][count];

    int ans = 0;
    int limit = tight ? (num[idx] - '0') : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        // Calculate new tight condition
        bool next_tight = tight && (digit == limit);
        
        // Calculate new constraint condition
        int next_count = count + (digit == 2);

        // State transition
        ans += solve(idx + 1, next_tight, next_count);
    }

    return dp[idx][tight][count] = ans;
}

int countNumbersUpTo(int X) {
    if (X < 0) return 0;
    num = to_string(X);
    memset(dp, -1, sizeof(dp));
    return solve(0, true, 0);
}

int main() {
    int L = 1, R = 324;
    // To find numbers in range [L, R], use the prefix property: f(R) - f(L-1)
    int result = countNumbersUpTo(R) - countNumbersUpTo(L - 1);
    cout << "Count: " << result << endl;
    return 0;
}