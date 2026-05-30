#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    // Helper function to update a value at a specific index
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // Helper function to query the maximum value in range [L, R]
    int query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0; // Outside the range
        }
        if (L <= start && end <= R) {
            return tree[node]; // Entirely inside the range
        }
        int mid = start + (end - start) / 2;
        int left_max = query(2 * node, start, mid, L, R);
        int right_max = query(2 * node + 1, mid + 1, end, L, R);
        return max(left_max, right_max);
    }

public:
    SegmentTree(int maxSize) {
        n = maxSize;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int L, int R) {
        if (L > R) return 0;
        return query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Step 1: Find the maximum possible coordinate 'x' to size our Segment Tree
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        // Safety boundary buffer
        int limit = max_x + 2; 

        // Initialize our Gap Diary (Segment Tree) and Obstacle tracker (Set)
        SegmentTree st(limit);
        set<int> obstacles;
        
        // We add 0 as a virtual starting obstacle to make distance calculation clean
        obstacles.insert(0);
        
        vector<bool> results;

        for (const auto& q : queries) {
            int type = q[0];
            
            if (type == 1) {
                int x = q[1];
                
                // Find the existing obstacles to the left and right of this new obstacle 'x'
                auto it = obstacles.upper_bound(x);
                int right_obstacle = (it != obstacles.end()) ? *it : -1;
                int left_obstacle = *prev(it);
                
                // Add the new obstacle
                obstacles.insert(x);
                
                // Update the gaps in our diary
                // 1. New gap from left_obstacle to x (stored at x)
                st.update(x, x - left_obstacle);
                
                // 2. If there was an obstacle to the right, its gap has shrunk!
                // It used to be (right_obstacle - left_obstacle), now it's (right_obstacle - x)
                if (right_obstacle != -1) {
                    st.update(right_obstacle, right_obstacle - x);
                }
                
            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];
                
                // Find the closest obstacle to the left of (or exactly at) 'x'
                auto it = obstacles.upper_bound(x);
                int prev_obstacle = *prev(it);
                
                // Part A: Check the biggest fully enclosed gap to the left of our previous obstacle
                int max_left_gap = st.query(0, prev_obstacle);
                
                // Part B: Check the remaining partial gap truncated by the limit 'x'
                int tail_gap = x - prev_obstacle;
                
                // The ultimate largest gap available before x
                int best_gap = max(max_left_gap, tail_gap);
                
                // If our block size fits in the best gap, it's a match!
                results.push_back(best_gap >= sz);
            }
        }
        
        return results;
    }
};