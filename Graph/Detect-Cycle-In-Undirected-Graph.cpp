#include<bits/stdc++.h>

using namespace std;


bool dfs(int node, int parent, const vector<vector<int>>& adj, vector<char>& visited) {
    visited[node] = 1;

    for(int nei: adj[node]) {
        if(!visited[nei]) {
            if(dfs(nei, node, adj, visited)) {
                return true;
            }
        }
        else if(nei != parent) {
            return true;
        }
    }

    return false;
}   

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<char> visited(n, 0);

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dfs(i, -1, adj, visited)) {
            return true;
        }
    }
    return false;
}