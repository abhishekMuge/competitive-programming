#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        // Available servers: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > available;

        // Busy servers: {finishTime, weight, index}
        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > busy;

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        // Initially, every server is available.
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        long long currentTime = 0;

        for (int j = 0; j < m; j++) {

            // A task cannot be processed before it arrives.
            currentTime = max(currentTime, (long long)j);

            // Release all servers that have completed their tasks.
            while (!busy.empty() &&
                   get<0>(busy.top()) <= currentTime) {

                auto [finishTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If every server is busy, jump to the earliest finish time.
            if (available.empty()) {

                currentTime = get<0>(busy.top());

                // Multiple servers may finish simultaneously.
                while (!busy.empty() &&
                       get<0>(busy.top()) <= currentTime) {

                    auto [finishTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server.
            auto [weight, index] = available.top();
            available.pop();

            ans[j] = index;

            // Calculate when this server will become free.
            long long finishTime = currentTime + tasks[j];

            busy.push({finishTime, weight, index});
        }

        return ans;
    }
};
