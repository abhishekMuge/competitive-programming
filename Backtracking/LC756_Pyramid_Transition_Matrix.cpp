#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(const string &row)
    {
        // Base case
        if (row.size() == 1)
        {
            return true;
        }

        // Memo check
        if (memo.count(row))
        {
            return memo[row];
        }

        int n = row.size();
        vector<string> nextRows;
        string curr;

        // Generate all possible next rows
        function<void(int)> build = [&](int idx)
        {
            if (idx == n - 1)
            {
                nextRows.push_back(curr);
                return;
            }

            string key;
            key.push_back(row[idx]);
            key.push_back(row[idx + 1]);

            if (mp.find(key) == mp.end())
                return;

            for (char ch : mp[key])
            {
                curr.push_back(ch);
                build(idx + 1);
                curr.pop_back();
            }
        };

        build(0);

        // Try each possible next row
        for (const string &next : nextRows)
        {
            if (dfs(next))
            {
                return memo[row] = true;
            }
        }

        return memo[row] = false;
    }

public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (auto &s : allowed)
        {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};