#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long val;

    Node(): val(0) {}

    Node(long long v) : val(v) {}
};

class SegmentTree {
private:
    int n;
    std::vector<Node> tree;

    // MUST DEFINE: How to combine a Left child and Right child into a Parent node
    Node merge(const Node& left, const Node& right) {
        Node parent;
        parent.val = left.val + right.val; // E.g., change to min(left.val, right.val) for Min Query
        return parent;
    }

    void build(const std::vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(arr[start]);
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = Node(val); // Update leaf
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        // Case 1: Out of range completely
        if (r < start || end < l) {
            return Node(); // Returns the default neutral element
        }
        // Case 2: Complete overlap
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Case 3: Partial overlap
        int mid = start + (end - start) / 2;
        Node leftResult = query(2 * node, start, mid, l, r);
        Node rightResult = query(2 * node + 1, mid + 1, end, l, r);
        return merge(leftResult, rightResult);
    }

public:
    SegmentTree(const std::vector<long long>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    // Point Update: Changes element at index 'idx' to 'val' -> O(log N)
    void updatePoint(int idx, long long val) {
        update(1, 0, n - 1, idx, val);
    }

    // Range Query: Aggregates value in range [l, r] -> O(log N)
    Node queryRange(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};