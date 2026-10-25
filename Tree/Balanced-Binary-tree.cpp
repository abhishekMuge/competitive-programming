#include <algorithm>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};

int checkBalancedTreeHeight(TreeNode* node) {
    if(node == nullptr) {
        return 0;
    }

    int leftHeight = checkBalancedTreeHeight(node->left);

    if(leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkBalancedTreeHeight(node->right);
    if(rightHeight == -1) {
        return -1;
    }

    if(abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return checkBalancedTreeHeight(root) != -1;
}