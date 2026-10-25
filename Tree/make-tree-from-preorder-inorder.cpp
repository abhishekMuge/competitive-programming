#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;

    TreeNode* build(
        const vector<int>& preorder,
        int left,
        int right
    ) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(
        vector<int>& preorder,
        vector<int>& inorder
    ) {
        inorderIndex.clear();
        preorderIndex = 0;

        for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        return build(
            preorder, 0, static_cast<int>(inorder.size()) - 1
        );
    }
};



/*
Go Lang solution

package main

type TreeNode struct {
    Val   int
    Left  *TreeNode
    Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
    inorderIndex := make(map[int]int, len(inorder))

    for i, val := range inorder {
        inorderIndex[val] = i
    }

    preorderIndex := 0

    var build func(int, int) *TreeNode

    build = func(left, right int) *TreeNode {
        if left > right {
            return nil
        }

        rootVal := preorder[preorderIndex]
        preorderIndex++

        root := &TreeNode{Val: rootVal}
        mid := inorderIndex[rootVal]

        root.Left = build(left, mid-1)
        root.Right = build(mid+1, right)

        return root
    }

    return build(0, len(inorder)-1)
}

*/