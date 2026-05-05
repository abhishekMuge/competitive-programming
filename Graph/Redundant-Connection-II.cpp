/*
Problem Statement

You are given a directed graph with n nodes and n edges.

👉 The graph was originally a rooted tree (no cycles, exactly one parent per node),
but one extra edge was added.

👉 Return the edge that should be removed to make it a valid tree again.


*/
#include<bits/stdc++.h>

using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // cycle
        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);

        vector<int> edge1, edge2;

        // Phase 1: check two parents
        for (auto& e : edges) {
            int u = e[0], v = e[1];

            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                edge1 = {parent[v], v}; // first parent
                edge2 = e;              // second parent
                e[1] = 0; // invalidate this edge
            }
        }

        // Phase 2: DSU
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (v == 0) continue; // skip invalid edge

            if (!dsu.unite(u, v)) {
                // cycle found
                if (edge1.empty())
                    return e;      // case 1
                return edge1;      // case 3
            }
        }

        return edge2; // case 2
    }
};