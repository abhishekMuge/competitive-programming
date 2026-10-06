#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } 
            else {
                if (balance > 0) {
                    // Match this ')' with an existing '('
                    balance--;
                } 
                else {
                    // No '(' available, so we must insert one
                    ans++;
                }
            }
        }

        // Any remaining '(' need a ')' each
        ans += balance;

        return ans;
    }
};