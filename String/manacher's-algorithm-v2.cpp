 #include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(const string& s) {
    if (s.empty()) {
        return "";
    }

    // Step 1: Transform the string.
    // Example: "abba" -> "#a#b#b#a#"
    string t = "#";

    for (char ch : s) {
        t += ch;
        t += '#';
    }

    int n = static_cast<int>(t.size());

    // Step 2: P[i] stores the palindrome radius at center i.
    vector<int> P(n, 0);

    // C = center of the rightmost palindrome.
    // R = right boundary of the rightmost palindrome.
    int C = 0;
    int R = 0;

    // Track the longest palindrome.
    int maxLen = 0;
    int maxCenter = 0;

    // Step 3: Process every possible center.
    for (int i = 0; i < n; i++) {

        // Case 1: i is inside the current rightmost palindrome.
        if (i < R) {
            int mirror = 2 * C - i;

            P[i] = min(R - i, P[mirror]);
        }

        // Case 2: Expand around center i.
        while (i + P[i] + 1 < n &&
               i - P[i] - 1 >= 0 &&
               t[i + P[i] + 1] == t[i - P[i] - 1]) {

            P[i]++;
        }

        // Step 4: Update the rightmost palindrome.
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }

        // Step 5: Update the longest palindrome.
        if (P[i] > maxLen) {
            maxLen = P[i];
            maxCenter = i;
        }
    }

    // Step 6: Convert transformed indices to original indices.
    int start = (maxCenter - maxLen) / 2;

    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s) << '\n';

    return 0;
}