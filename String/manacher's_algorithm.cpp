#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";

    // Step 1: Preprocess the string with separators and sentinels
    // e.g., "babad" becomes "^#b#a#b#a#d#$"
    std::string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.length();
    std::vector<int> p(n, 0); // Radius array
    int c = 0, r = 0;         // Center and Right boundary of current palindrome
    int max_len = 0;
    int center_index = 0;

    for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2 * c - i; // Calculate mirror index of i across center c

        // Leverage symmetry if i is within the current right boundary
        if (r > i) {
            p[i] = std::min(r - i, p[i_mirror]);
        }

        // Expand the palindrome centered at i
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }

        // If the palindrome expands past the right boundary, update C and R
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }

        // Keep track of the longest palindrome found
        if (p[i] > max_len) {
            max_len = p[i];
            center_index = i;
        }
    }

    // Extract the longest palindromic substring using the center and radius
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}

int main() {
    std::string test = "babad";
    std::cout << "Input:  " << test << '\n';
    std::cout << "Output: " << longestPalindrome(test) << '\n'; // "bab" or "aba"
    
    std::string test2 = "cbbd";
    std::cout << "Input:  " << test2 << '\n';
    std::cout << "Output: " << longestPalindrome(test2) << '\n'; // "bb"
    
    return 0;
}