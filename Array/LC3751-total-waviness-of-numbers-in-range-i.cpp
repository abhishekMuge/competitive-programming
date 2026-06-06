#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getWaviness(int num) {
        string s = to_string(num);

        if (s.size() < 3)
            return 0;

        int waviness = 0;

        for (int i = 1; i < (int)s.size() - 1; ++i) {
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) {
                ++waviness; // Peak
            }
            else if (s[i] < s[i - 1] && s[i] < s[i + 1]) {
                ++waviness; // Valley
            }
        }

        return waviness;
    }
    int totalWaviness(int num1, int num2) {
        long long ans = 0;

        for (int num = num1; num <= num2; ++num) {
            ans += getWaviness(num);
        }

        return ans;
    }
};