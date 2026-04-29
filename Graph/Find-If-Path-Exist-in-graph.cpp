#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }

        return false;
    }
};

bool dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& vis) {
    if (node == dest) return true;

    vis[node] = 1;

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            if (dfs(nei, dest, adj, vis))
                return true;
        }
    }

    return false;
}