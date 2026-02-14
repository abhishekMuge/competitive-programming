#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vals)
    {
        if (!root)
            return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    TreeNode *build(const vector<int> &vals, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(vals[mid]);

        root->left = build(vals, left, mid - 1);
        root->right = build(vals, mid + 1, right);

        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, vals.size() - 1);
    }
};
