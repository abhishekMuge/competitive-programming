#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool KMP(const string& text, const string& pattern)
    {
        vector<int> lps(pattern.size(),0);

        int len = 0;

        for(int i = 1; i < pattern.size(); )
        {
            if(pattern[i] == pattern[len])
            {
                lps[i++] = ++len;
            }
            else
            {
                if(len)
                    len = lps[len-1];
                else
                    i++;
            }
        }

        int i = 0;
        int j = 0;

        while(i < text.size())
        {
            if(text[i] == pattern[j])
            {
                i++;
                j++;
            }

            if(j == pattern.size())
                return true;

            else if(i < text.size() && text[i] != pattern[j])
            {
                if(j)
                    j = lps[j-1];
                else
                    i++;
            }
        }

        return false;
    }
    int numOfStrings(vector<string>& patterns, string word)
    {
        int ans = 0;

        for(auto &p : patterns)
        {
            if(KMP(word,p))
                ans++;
        }

        return ans;
    }
};