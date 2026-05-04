#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // b → a
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push nodes with 0 indegree
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);

            for (int neigh : adj[node]) {
                if (--indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // Cycle check
        if (result.size() != numCourses)
            return {}; // cycle exists

        return result;
    }
};