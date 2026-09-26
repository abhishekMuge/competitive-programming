#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map <string, string> info;
        
        for(auto k: knowledge) {
            info[k[0]] = k[1];
        }
        bool addKey = false;
        string key, res;

        for(char c: s) {
            if(c == '(') {
                addKey = true;
            }
            else if(c == ')') {
                if(info.count(key) > 0) {
                    res += info[key];
                }
                else {
                    res.push_back('?');
                }
                addKey = false;
                key.clear();
            }
            else if(addKey) {
                key.push_back(c);
            }
            else {
                res.push_back(c);
            }
        }
        return res;
    }
};