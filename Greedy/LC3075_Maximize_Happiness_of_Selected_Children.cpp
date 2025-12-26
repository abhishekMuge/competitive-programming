#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        int turns = 0;

        for (int i = 0; i < k; i++)
        {
            ans += max(happiness[i] - turns, 0);
            turns++;
        }
        return ans;
    }
};