#include<bits/stdc++.h>

using namespace std;


/*

Since nums is already sorted, every adjacent pair whose difference exceeds maxDiff forms a barrier that 
cannot be crossed. Therefore, the array is naturally divided into connected components.

Instead of using a DSU, we can directly assign each index a component number. Whenever we encounter a barrier, we increment the component number. Two indices can reach each other
 if and only if they belong to the same component.
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> components(n, 0);

        int compId = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] > maxDiff) {
                compId++;
            }
            components[i] = compId;
        }

        vector<bool> ans;
        for(auto &q : queries) {
            ans.push_back(components[q[0]] == components[q[1]]);
        }
        return ans;
    }
};


class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        // Initially, every node is its own parent
        std::iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 1);
    }

    // Find with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union by rank
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

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
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        UnionFind dsu(n);

        // Connect adjacent elements if they satisfy the condition
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                dsu.unite(i, i + 1);
            }
        }

        // Process all queries
        std::vector<bool> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            
            // If they have the same representative root, a path exists
            answer.push_back(dsu.find(u) == dsu.find(v));
        }

        return answer;
    }
};

