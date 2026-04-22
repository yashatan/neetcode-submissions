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
    int kthSmallest(TreeNode* root, int k) {

        vector<int> resArray;
        inordertostack(resArray, root);
        return resArray[k-1];
    }

    void inordertostack(vector<int>& arraynode, TreeNode* root){
        if (!root){
            return;
        }

        inordertostack(arraynode,root->left);
        arraynode.push_back(root->val);
        inordertostack(arraynode,root->right);
    }
};
