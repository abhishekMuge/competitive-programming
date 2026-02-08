#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool backtrack(vector<int> &matchsticks, vector<int> &sides, int index, int target)
    {
        // all matchsticks has been places
        if (index == matchsticks.size())
        {
            return true;
        }
        int currentStick = matchsticks[index];

        for (int i = 0; i < 4; ++i)
        {
            // can current stick be fit into this side
            if (sides[i] + currentStick <= target)
            {
                // If this side is the same as the previous side we just tried, skip it.
                bool alreadyTried = false;
                for (int j = 0; j < i; ++j)
                {
                    if (sides[j] == sides[i])
                    {
                        alreadyTried = true;
                        break;
                    }
                }
                if (alreadyTried)
                    continue;
                sides[i] += currentStick;

                if (backtrack(matchsticks, sides, index + 1, target))
                {
                    return true;
                }
                sides[i] -= currentStick;
            }
        }
        return false;
    }
    bool makesquare(vector<int> &matchsticks)
    {
        long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);

        if (sum == 0 || sum % 4 != 0)
            return false;
        int target = sum / 4;

        sort(matchsticks.begin(), matchsticks.end());

        if (matchsticks[0] > target)
            return false;

        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, target);
    }
};