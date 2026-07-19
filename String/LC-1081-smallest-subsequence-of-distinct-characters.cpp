#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        for(int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> used(26, false);

        string str;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if(used[ch - 'a']) {
                continue;
            }

            while(!str.empty() &&
                    str.back() > ch && 
                    last[str.back() - 'a'] > i
                ) {
                    used[str.back() - 'a'] = false;
                    str.pop_back();
                }
            str.push_back(ch);
            used[ch - 'a'] = true;
        }
        return str;
    }
};