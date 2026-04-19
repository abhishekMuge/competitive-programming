#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
private:
    vector<vector<int>> rects;
    vector<ll> prefix_sum;
    ll total_sum = 0;

    mt19937 gen;
    uniform_int_distribution<ll> dist; 

public:
    Solution(vector<vector<int>>& rects) : rects(rects), gen(random_device{}()) {
        for(const auto& r: rects) {
            ll points = (ll)(r[2] - r[0] + 1) * (r[3] - r[1]+1);
            total_sum += points;
            prefix_sum.push_back(total_sum);
        }
        dist = uniform_int_distribution<ll>(1, total_sum);
    }
    
    vector<int> pick() {
        ll target = dist(gen);
        auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), target);
        int idx = distance(prefix_sum.begin(), it);

        const auto &r = rects[idx];

        uniform_int_distribution<int> distX{r[0], r[2]};
        uniform_int_distribution<int> distY{r[1], r[3]};

        return { distX(gen), distY(gen) };
    }
};