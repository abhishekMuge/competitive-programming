#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    // Convert needs vector to string key for memo
    string getKey(vector<int> &needs)
    {
        string key;
        for (int n : needs)
        {
            key += to_string(n) + "#";
        }
        return key;
    }

    int dfs(vector<int> &price, vector<vector<int>> &special,
            vector<int> &needs, unordered_map<string, int> &memo)
    {

        string key = getKey(needs);
        if (memo.count(key))
            return memo[key];

        int n = price.size();

        // Option 1: buy everything individually
        int minCost = 0;
        for (int i = 0; i < n; i++)
            minCost += needs[i] * price[i];

        // Option 2: try every special offer
        for (auto &offer : special)
        {

            vector<int> newNeeds = needs;
            bool valid = true;

            // Check if offer can be applied
            for (int i = 0; i < n; i++)
            {
                if (offer[i] > newNeeds[i])
                {
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }

            if (valid)
            {
                minCost = min(minCost,
                              offer[n] + dfs(price, special, newNeeds, memo));
            }
        }

        memo[key] = minCost;
        return minCost;
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        unordered_map<string, int> memo;
        return dfs(price, special, needs, memo);
    }
};