#include <bits/stdc++.h>

using namespace std;
// Time complexity = O(n * 2^n-1)
class solution
{
public:
    bool dfs(int pIndex, int sIndex, string pattern, string str, unordered_map<char, string> &p2s, unordered_map<string, char> &s2p)
    {
        // base case
        if (pIndex == pattern.size() && sIndex == str.size())
            return true;
        // if one is consumed but another is not -> invalid
        if (pIndex == pattern.size() || sIndex == str.size())
            return false;

        char ch = pattern[pIndex];
        // if character is already mapped
        if (p2s.count(ch))
        {
            const string &mapped = p2s[ch];
            int len = mapped.length();

            if (sIndex + len > str.size())
            {
                return false;
            }
            if (str.substr(sIndex, len) != mapped)
                return false;

            return dfs(pIndex + 1, sIndex + len, pattern, str, p2s, s2p);
        }
        // character is not mapped
        for (int end = sIndex; end < str.size(); ++end)
        {
            string candidate = str.substr(sIndex, end - sIndex + 1);

            if (s2p.count(candidate))
                continue;
            ;

            p2s[ch] = candidate;
            s2p[candidate] = ch;

            if (dfs(pIndex + 1, end + 1, pattern, str, p2s, s2p))
                return true;

            p2s.erase(ch);
            s2p.erase(candidate);
        }
        return false;
    }
    bool isWordPatternMatch(string pattern, string str)
    {
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;

        return dfs(0, 0, pattern, str, p2s, s2p);
    }
}
