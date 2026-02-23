#include <bits/stdc++.h>

using namespace std;;

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int ans = 0;
        int index = 0;

        while (n > 0) {
            if (n & 1) {   // if LSB is 1
                if (prev != -1) {
                    ans = max(ans, index - prev);
                }
                prev = index;
            }
            n >>= 1;
            index++;
        }

        return ans;
    }
};