#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26, 0), odd(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        return even == vector<int>(26, 0) && odd == vector<int>(26, 0);
    }
};


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        int counts[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            int offset = (i & 1) << 7;
            counts[offset + s1[i]]++;
            counts[offset + s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) {
                return false;
            }
        }

        return true;
    }
};