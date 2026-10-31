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
    bool isBalanced(TreeNode* root) {
        bool res = (bool) dfs(root).first;

        return res;
    }

    pair<bool, int> dfs(TreeNode* root) {
        bool balance = false;
        int height = 0;

        if (!root) {
            return pair<bool, int>{true, 0};
        }
        auto left =  dfs(root->left);
        auto right = dfs(root->right);

        if ((left.second - right.second) > 1 || (right.second - left.second) > 1 || !left.first || !right.first) {
            balance = false;
        } else {
            balance = true;
        }

        height = 1 + max(left.second, right.second);

        return pair<bool, int>{balance, height};
    }
};
