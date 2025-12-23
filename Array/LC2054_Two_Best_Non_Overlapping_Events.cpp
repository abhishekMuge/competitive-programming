#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();

        // first sort by start time
        sort(events.begin(), events.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });

        auto endSorted = events;
        sort(endSorted.begin(), endSorted.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] < b[1];
             });

        int bestEndValue = 0;
        int endPtr = 0;
        int ans = 0;

        for (const auto &e : events)
        {
            int start = e[0];
            int value = e[2];

            while (endPtr < n && endSorted[endPtr][1] < start)
            {
                bestEndValue = max(bestEndValue, endSorted[endPtr][2]);
                endPtr++;
            }
            // take only 1 value
            ans = max(ans, value);

            ans = max(ans, bestEndValue + value);
        }
        return ans;
    }
};