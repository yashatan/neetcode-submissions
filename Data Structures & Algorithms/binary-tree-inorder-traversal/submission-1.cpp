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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversalGoThrough(res,root);
        return res;
    }

    void inorderTraversalGoThrough(vector<int>& resarray, TreeNode* root){
        if(!root){
            return;
        }

        inorderTraversalGoThrough(resarray,root->left);
        resarray.push_back(root->val);
        inorderTraversalGoThrough(resarray,root->right);
    }
};