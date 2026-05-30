#include <bits/stdc++.h>

using namespace std;

class SegmentTreeImpl {
private:
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& arr, int treeIndex, int low, int high) {
        if(low == high) {
            tree[treeIndex] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        buildTree(arr, leftChild, low, mid);
        buildTree(arr, rightChild, mid+1, high);

        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }

    //range query function

    int rangeQuery(int treeIndex, int low, int high, int qL, int qR) {
        if(qL <= low && qR >= high) {
            return tree[treeIndex];
        }
        //total overlap
        if(high < qL || low > qR) {
            return 0;
        }

        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        int leftSum = rangeQuery(leftChild, low, mid, qL, qR);
        int rightSum = rangeQuery(rightChild, mid+1, high, qL, qR);

        return leftSum + rightSum;
    }

    void updateSement(int treeIndex, int low, int high, int arrIndex, int newValue) {
        if(low == high) {
            tree[treeIndex] = newValue;
            return;
        }

        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        if(arrIndex <= mid) {
            updateSement(leftChild, low, mid, arrIndex, newValue);
        }
        else {
            updateSement(rightChild, mid+1, high, arrIndex, newValue);
        }

        tree[treeIndex] = tree[leftChild] + tree[rightChild];
    }

public:
    SegmentTreeImpl(const vector<int>& arr) {
        n = arr.size();
        // Safe size allocation for a segment tree is 4 * n
        tree.resize(4 * n, 0);
        buildTree(arr, 0, 0, n - 1);
    }

    // Public wrapper for query
    int query(int qL, int qR) {
        return rangeQuery(0, 0, n - 1, qL, qR);
    }

    // Public wrapper for update
    void update(int arrIndex, int newValue) {
        updateSement(0, 0, n - 1, arrIndex, newValue);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7};
    SegmentTreeImpl st(arr);

    // Query 1: Sum of elements from index 1 to 3 (3 + 5 + 7)
    cout << "Sum of range (1, 3): " << st.query(1, 3) << endl; // Output: 15

    // Update: Change element at index 1 from 3 to 10. (Array becomes [1, 10, 5, 7])
    st.update(1, 10);
    cout << "Updated index 1 to 10." << endl;

    // Query 2: Sum of elements from index 1 to 3 again (10 + 5 + 7)
    cout << "Sum of range (1, 3): " << st.query(1, 3) << endl; // Output: 22

    return 0;
}

/*

Build Tree -> O(n)  Traverses and populates all nodes once.
Query Range O(log n) At max, 4 nodes are processed at each level of the tree.
Update Point O(log n) Traverses a single path from root to leaf.
Space O(n) Uses a fixed 4n size array.
*/