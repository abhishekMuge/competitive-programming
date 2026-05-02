#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isGood(int num, unordered_map<char, char>& rotateMap) {
        string original = to_string(num);
        string rotated = "";
        bool hasChanged = false;

        for (char digit : original) {
            // Check if the digit is invalid
            if (rotateMap.find(digit) == rotateMap.end()) {
                return false; // Invalid digit found
            }
            char rotatedDigit = rotateMap[digit];
            rotated += rotatedDigit;
            if (rotatedDigit != digit) {
                hasChanged = true;
            }
        }

        return hasChanged; // Must be different from original
    }
    int rotatedDigits(int n) {
        unordered_map<char, char> rotateMap = {
        {'0', '0'},
        {'1', '1'},
        {'2', '5'},
        {'5', '2'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}
        };
 
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGood(i, rotateMap)) {
                count++;
            }
        }

        return count;   
    }
};