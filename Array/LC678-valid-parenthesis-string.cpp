#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            } else if(c == ')') {
                low--;
                high--;

            } else {
                low--;
                high++;
            }

            if(high < 0 ) return false;
            if(low < 0) low = 0;
        }
        return low == 0;
    }
};

//DP APPROACH
class Solution {
public:
    bool checkValidString(std::string s) {
        int n = s.length();
        // memo[i][open] will store:
        //  -1 : state not yet visited
        //   0 : false (invalid)
        //   1 : true (valid)
        std::vector<std::vector<int>> memo(n, std::vector<int>(n + 1, -1));
        
        return solve(0, 0, s, memo);
    }

private:
    bool solve(int i, int open, const std::string& s, std::vector<std::vector<int>>& memo) {
        // Base Case 1: More ')' than '(', invalid state
        if (open < 0) return false;

        // Base Case 2: Reached end of string, valid only if all '(' are matched
        if (i == s.length()) return open == 0;

        // Return memoized result if already calculated
        if (memo[i][open] != -1) return memo[i][open];

        bool isValid = false;

        if (s[i] == '(') {
            isValid = solve(i + 1, open + 1, s, memo);
        } else if (s[i] == ')') {
            isValid = solve(i + 1, open - 1, s, memo);
        } else { // s[i] == '*'
            // Try all 3 options:
            // 1. Treat '*' as '(' -> open + 1
            // 2. Treat '*' as ')' -> open - 1
            // 3. Treat '*' as ""  -> open
            isValid = solve(i + 1, open + 1, s, memo) ||
                      solve(i + 1, open - 1, s, memo) ||
                      solve(i + 1, open, s, memo);
        }

        // Store result in memo table before returning
        return memo[i][open] = isValid;
    }
};