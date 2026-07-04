#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        // Step 1: Build the adjacency list
        // graph[u] stores pairs of {neighbor, distance}
        std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            graph[u].push_back({v, dist});
            graph[v].push_back({u, dist});
        }

        // Step 2: BFS traversal to find all reachable cities from City 1
        std::vector<bool> visited(n + 1, false);
        std::queue<int> q;
        
        q.push(1);
        visited[1] = true;
        int min_score = INT_MAX;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Explore all roads connected to the current city
            for (const auto& neighbor_pair : graph[curr]) {
                int neighbor = neighbor_pair.first;
                int distance = neighbor_pair.second;

                // Since this road is connected to a reachable city, 
                // it's part of our component. Track its distance.
                min_score = std::min(min_score, distance);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return min_score;
    }
};


//union find


#include <vector>
#include <algorithm>
#include <climits>

class DisjointSet {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        // Initially, every node is its own parent
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation with Path Compression
    int find_root(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find_root(parent[i]); // Path compression optimization
    }

    // Union operation by Rank
    void union_sets(int i, int j) {
        int root_i = find_root(i);
        int root_j = find_root(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) {
                parent[root_i] = root_j;
            } else if (rank[root_i] > rank[root_j]) {
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};

class Solution {
public:
    int minScore(int n, std::vector<std::vector<int>>& roads) {
        DisjointSet dsu(n);

        // Step 1: Group all connected cities together
        for (const auto& road : roads) {
            dsu.union_sets(road[0], road[1]);
        }

        // Step 2: Find the ultimate representative (root) of City 1
        int root_1 = dsu.find_root(1);
        int min_score = INT_MAX;

        // Step 3: Find the minimum edge weight belonging to City 1's component
        for (const auto& road : roads) {
            int u = road[0];
            // Since u and v are already unioned, checking either endpoint's root works
            if (dsu.find_root(u) == root_1) {
                min_score = std::min(min_score, road[2]);
            }
        }

        return min_score;
    }
};