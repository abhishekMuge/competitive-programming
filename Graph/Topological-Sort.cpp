#include <vector>
#include <queue>
#include <iostream>

std::vector<int> kahnTopologicalSort(int n, std::vector<std::vector<int>>& adj) {
    std::vector<int> in_degree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adj[i]) {
            in_degree[neighbor]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    std::vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If topo_order.size() != n, there is a cycle
    return topo_order;
}