#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>

using namespace std;

constexpr int MAXN = 100005;

class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> inDegree(n, 0);

        bitset<MAXN> suspicious;

        for (const auto& inv : invocations) {
            edges[inv[0]].push_back(inv[1]);
            inDegree[inv[1]]++;
        }

        queue<int> q;
        q.push(k);

        suspicious.set(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : edges[u]) {
                inDegree[v]--;

                if (!suspicious.test(v)) {
                    q.push(v);
                    suspicious.set(v);
                }
            }
        }

        bool canRemoveAll = true;
        vector<int> remaining;

        for (int i = 0; i < n; i++) {
            if (suspicious.test(i) && inDegree[i] > 0) {
                canRemoveAll = false;
                break;
            } else if (!suspicious.test(i)) {
                remaining.push_back(i);
            }
        }

        if (!canRemoveAll) {
            vector<int> allNodes(n);
            iota(allNodes.begin(), allNodes.end(), 0);
            return allNodes;
        }

        return remaining;
    }

    vector<int> remainingMethods_Approach2(
        int n,
        int k,
        vector<vector<int>>& invocations)
        {
            vector<vector<int>> edges(n);

            for (auto & inv : invocations) {
                edges[inv[0]].push_back(inv[1]);
            }

            vector<bool> sus (n, false);

            queue<int> q;
            q.push(k);
            sus[k] = true;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v : edges[u]) {
                    if(!sus[v]) {
                        sus[v] = true;
                        q.push(v);
                    }
                }
            }

            // Check if an outside method calls a suspicious one
            for (auto &edge : invocations)
            {
                int u = edge[0];
                int v = edge[1];

                if (!sus[u] && sus[v])
                {
                    vector<int> all(n);
                    iota(all.begin(), all.end(), 0);
                    return all;
                }
            }

            // Return remaining methods
            vector<int> ans;

            for (int i = 0; i < n; i++)
            {
                if (!sus[i])
                    ans.push_back(i);
            }

            return ans;
        }
};

