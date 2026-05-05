/*
Problem Statement

You are given a directed graph where:

graph[i] = list of nodes you can go to from node i

👉 A node is eventually safe if:

starting from it, you will never enter a cycle, no matter which path you take

👉 Return all safe nodes in sorted order

🔁 Step 1: Reverse the graph

Original:

u → v

Reverse:

v → u
🧠 Why reverse?

Because:

We want to propagate "safety" backward
🧩 Step 2: Use Kahn’s Algorithm

But instead of indegree:
👉 we track outdegree

🔄 Process
Compute outdegree[i]
Push nodes with outdegree = 0 (terminal nodes)
BFS:
mark node safe
for each parent (in reverse graph):
reduce outdegree
if becomes 0 → push

Why Reverse Graph?

Reverse graph flips direction:

v → u

Now you can do:

Start from safe nodes → propagate safety backward


Complexity
Time: O(V + E)
Space: O(V + E)

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeSates(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> revGraph;
        vector<int> outDeg {n, 0};

        //build reverse graph

        for(int i = 0; i < n; i++) {
            outDeg[i] = graph[i].size();

            for(int nei: graph[i]) {
                revGraph[nei].push_back(i);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(outDeg[i] == 0) q.push(i);
        }

        vector<bool> safe(n, false);

        while(!q.empty()) {
            int node = q.front(); q.pop();
            safe[node] = true;

            for(int parent: revGraph[node]) {
                if(--outDeg[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                result.push_back(i);
        }

        return result;

    }
}