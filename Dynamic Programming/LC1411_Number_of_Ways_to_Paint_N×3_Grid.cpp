#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        const long long MOD = 1e9 + 7;

        // dpA -> ABC pattern count
        // dpB -> ABA pattern count
        long long dpA = 6;  // base case for row 1
        long long dpB = 6;

        for (int i = 2; i <= n; i++) {
            long long newA = (dpA * 2 + dpB * 2) % MOD;
            long long newB = (dpA * 2 + dpB * 3) % MOD;

            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};
