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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (!root && !subRoot) {
            return true;
        }

        return checkNormal(root, subRoot);
    }

    bool checkNormal(TreeNode* root, TreeNode* subRoot) {

        if ((!root && subRoot) || (root && !subRoot)) {
            return false;
        }
        cout << root->val << endl;
        if (root->val != subRoot->val) {
            return checkNormal(root->left, subRoot) || checkNormal(root->right, subRoot);
        }
        else {
            if (checkEqual(root, subRoot)) {
                return true;
            }
            else {
                return checkNormal(root->left, subRoot) || checkNormal(root->right, subRoot);
            }
        }
    }


    bool checkEqual(TreeNode* root, TreeNode* subRoot) {

        if (!root && !subRoot) {
            return true;
        }

        if ((!root && subRoot) || (root && !subRoot)) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        if ((!root->left && !root->right && !subRoot->left && !subRoot->right)) {
            return true;
        }
        return checkEqual(root->left, subRoot->left) && checkEqual(root->right, subRoot->right);
    }
};
