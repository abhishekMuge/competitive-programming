#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());

        int n = events.size();
        int attended = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int eventIdx = 0;

        int maxEventDay = 0;
        for (auto &e : events)
        {
            maxEventDay = max(maxEventDay, e[1]);
        }

        for (int day = 1; day <= maxEventDay; i++)
        {
            while (eventIdx < n && events[eventIdx][0] == day)
            {
                minHeap.emplace(events[eventIdx][1]);
                eventIdx++;
            }

            while (!minHeap.empty() && minHeap.top() < day)
            {
                minHeap.pop();
            }

            if (!minHeap.empty())
            {
                minHeap.pop();
                attended++;
            }
        }
        return attended;
    }
};