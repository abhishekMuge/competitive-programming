#include<bits/stdc++.h>

using namespace std;

/*
Union find Template
*/

class UnionFind {
private: 
    std::vector<int> parents;
    std::vector<int> ranks;
    int nums_components;

public:
    UnionFind(int n) : nums_components(n) {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
        ranks.assign(n, 0);
    }

    int find(int i) {
        if(parents[i] = i) //its self parent
            return i;
        return parents[i] = find(parents[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j) {
            if(ranks[root_i] < ranks[root_j]) {
                parents[root_i] = root_j;
            } else if(ranks[root_i] > ranks[root_j]) {
                parents[root_j] = root_i;
            } else {
                parents[root_i] = root_j;
                ranks[root_j]++;
            }
            nums_components--;
            return true;
        }
        return false;
    }

    int count() const {
        return nums_components;
    }
};