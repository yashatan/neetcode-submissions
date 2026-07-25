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
    bool isValidBST(TreeNode* root) {
        return (checkValidBST(root->left, -1001, root->val) && checkValidBST(root->right, root->val, 1001));
    }

    bool checkValidBST(TreeNode* root, int minVal, int maxVal) {
        if (!root) return true;

        if (((root->val < maxVal) && (root->val > minVal))) {
            return (checkValidBST(root->left, minVal, root->val) && checkValidBST(root->right, root->val, maxVal));
        }

        return false;
    }
};
