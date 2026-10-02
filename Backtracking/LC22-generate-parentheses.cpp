#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void backtrack(std::vector<std::string>& result, std::string current, int openCount, int closeCount, int n) {
        // Base case: string length reaches 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Choice 1: Add an opening bracket if we have fewer than n
        if (openCount < n) {
            backtrack(result, current + "(", openCount + 1, closeCount, n);
        }

        // Choice 2: Add a closing bracket if openCount > closeCount
        if (closeCount < openCount) {
            backtrack(result, current + ")", openCount, closeCount + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};