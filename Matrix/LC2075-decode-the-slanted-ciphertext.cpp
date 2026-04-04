#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (encodedText.empty()) return encodedText;

        int n    = encodedText.size();
        int cols = (n + rows - 1) / rows;   // ceil division without float
        string decoded;
        decoded.reserve(n);

        for (int start = 0; start < cols; start++) {
            int r = 0, c = start;
            while (r < rows && c < cols) {
                decoded += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        // Strip trailing spaces
        int last = (int)decoded.size();
        while (last > 0 && decoded[last - 1] == ' ') last--;
        return decoded.substr(0, last);
    }
};