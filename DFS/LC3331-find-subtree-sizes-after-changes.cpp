#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent(n);
        new_parent[0] = -1;
        vector<int> last_seen(26, -1);

        // Step 1: Find the closest ancestor y with s[y] == s[u] for every node u
        auto find_new_parents = [&](auto& self, int u) -> void {
            if (u > 0) {
                int c = s[u] - 'a';
                new_parent[u] = (last_seen[c] != -1) ? last_seen[c] : parent[u];
            }

            int c = s[u] - 'a';
            int prev = last_seen[c];
            last_seen[c] = u;

            for (int v : adj[u]) {
                self(self, v);
            }

            // Backtrack so only true ancestors of deeper nodes remain in last_seen
            last_seen[c] = prev;
        };

        find_new_parents(find_new_parents, 0);

        // Step 2: Construct the final tree from new_parent
        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        // Step 3: Compute subtree sizes in the final tree
        vector<int> ans(n, 1);
        auto compute_sizes = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : final_adj[u]) {
                size += self(self, v);
            }
            return ans[u] = size;
        };

        compute_sizes(compute_sizes, 0);
        return ans;
    }
};
