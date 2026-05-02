#include<bits/stdc++.h>

using namespace std;

/*
1. Undirected Graph
✅ Key Idea:

1. A cycle exists if you visit a node that is:
2. already visited
3. AND not your parent


🔹 DFS Approach (Undirected)
Logic:
1.Maintain visited[]
2. Pass parent in recursion
3. If neighbor is visited AND not parent → cycle

*/

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

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
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -i, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}


//* BFS approach

bool hasCycleBFSVersion(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({start, -1});

    visited[start] = true;

    while(!q.empty()) {
        auto [node, parent] = q.front();
        q.pop();

        for(int nei: adj[start]) {
            if(!visited[nei]){
                visited[nei] = true;
                q.push({nei, node });
            }
            else if(nei != node ) {
                return true;
            }
        }
    }
    return false;
}