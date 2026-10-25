#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int maxsum = INT_MIN;

    int dfs(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int leftGain = max(0, dfs(node->left));
        int rightGain = max(0, dfs(node->right));

        int currentPath = node->val + leftGain + rightGain;
        maxsum = max(maxsum, currentPath);


        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        dfs(root);
        return maxsum;
    }

};

