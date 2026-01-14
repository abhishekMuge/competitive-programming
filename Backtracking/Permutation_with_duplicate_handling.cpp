#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void backtrack(
        const string &s,
        vector<bool> &used,
        string &current,
        vector<string> &result)
    {
        // Base case: permutation complete
        if (current.size() == s.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            // Skip already used characters
            if (used[i])
                continue;

            // Skip duplicates
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1])
            {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(s[i]);

            // Explore
            backtrack(s, used, current, result);

            // Un-choose
            current.pop_back();
            used[i] = false;
        }
    }

    vector<string> permuteUnique(string s)
    {
        vector<string> result;
        string current;
        vector<bool> used(s.size(), false);

        sort(s.begin(), s.end()); // required for duplicate handling
        backtrack(s, used, current, result);

        return result;
    }
};
