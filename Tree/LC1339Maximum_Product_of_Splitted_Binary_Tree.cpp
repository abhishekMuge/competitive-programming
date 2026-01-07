#include <bits/stdc++.h>

using namesapce std;
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
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    long long totalSum = 0;
    long long nMaxProduct = 0;

    // First DFS: compute total sum
    long long computeTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val
             + computeTotalSum(root->left)
             + computeTotalSum(root->right);
    }
    // Second DFS: compute subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subtreeSum = root->val + leftSum + rightSum;

        long long product = subtreeSum * (totalSum - subtreeSum);
        nMaxProduct = max(nMaxProduct, product);

        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum = computeTotalSum(root);
        dfs(root);
        return nMaxProduct % MOD;
    }
};