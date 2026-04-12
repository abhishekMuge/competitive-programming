#include <bits/stdc++.h>

using namespace std;

string longestSubstringWithoutRepeating(const string& s) {
    unordered_map<char, int> lastSeen;

    int left = 0;
    int maxLength = 0;
    int bestStart = 0;

    for (int right = 0; right < s.size(); right++) {
        char current = s[right];

        if (lastSeen.find(current) != lastSeen.end()) {
            left = max(left, lastSeen[current] + 1);
        }

        lastSeen[current] = right;

        if (right - left + 1 > maxLength) {
            maxLength = right - left + 1;
            bestStart = left;
        }
    }

    return s.substr(bestStart, maxLength);
}