#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // base
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {    
                st.pop();
                if (st.empty()) { //it send new baseline for calculating the maxLen
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top()); //here its trying to get substr len from bad base which is invaid ')' char without matching pair
                }
            }
        }
        return maxLen;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') left++;

            else right++;
            if(right > left) {
                left = right = 0;
            }
            if(left == right) {
                maxLen = max(maxLen, 2*right);
            }
        }

        left = right = 0;

        for(int i = n -1 ; i >= 0; i--) {
            if(s[i] == '(') left++;
            else right++;

            if(left == right) {
                maxLen = max(maxLen, 2*right);
            }
            if(right > left) {
                left = right = 0;
            }
        }

        return maxLen;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) return 0;

        vector<int> dp(n, 0);
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // Case 1: Simple pair "()"
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                // Case 2: Nested pair "))" matching an earlier '('
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    int prevValid = (i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0;
                    dp[i] = dp[i - 1] + 2 + prevValid;
                }
                
                maxLen = max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};