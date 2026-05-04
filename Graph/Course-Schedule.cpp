#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;

    for(int nei: adj[node]) {
        if(visited[nei] == 0) {
            if(dfs(nei, adj, visited)) {
                return true;
            }
        }
        else if(visited[nei] == 1) {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& pre) {
    vector<vector<int>> adj(numCourses);

    for(auto& p: pre) {
        adj[p[1]].push_back(p[0]); // b -> a
    }

    vector<int> state(numCourses, 0);

    for(int i = 0; i < numCourses; i++) {
        if(state[i]  == 0) {
            if(dfs(i, adj, state)) {
                return false;
            }
        }
    }
    return true;
}