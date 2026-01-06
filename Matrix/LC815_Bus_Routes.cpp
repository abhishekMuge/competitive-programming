#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes,
                              int source, int target)
    {

        if (source == target)
            return 0;

        // stop -> list of buses
        unordered_map<int, vector<int>> stopToBuses;
        for (int bus = 0; bus < routes.size(); bus++)
        {
            for (int stop : routes[bus])
            {
                stopToBuses[stop].push_back(bus);
            }
        }

        // BFS queue: (current stop)
        queue<int> q;
        q.push(source);

        unordered_set<int> visitedStops;
        visitedStops.insert(source);

        vector<bool> visitedBus(routes.size(), false);

        int busesTaken = 0;

        while (!q.empty())
        {
            int size = q.size();
            busesTaken++;

            while (size--)
            {
                int currStop = q.front();
                q.pop();

                for (int bus : stopToBuses[currStop])
                {
                    if (visitedBus[bus])
                        continue;

                    visitedBus[bus] = true;

                    for (int nextStop : routes[bus])
                    {
                        if (nextStop == target)
                            return busesTaken;

                        if (!visitedStops.count(nextStop))
                        {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
