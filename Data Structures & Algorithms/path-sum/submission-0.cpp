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
    int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checksum(root, sum,targetSum);
    }

    bool checksum(TreeNode* root, int& sum, int targetSum){
        if (!root){
            return false;
        }

        sum += root->val;

        if (!root->left && !root->right && sum == targetSum){
            return true;
        }
        if(checksum(root->left, sum,targetSum)){
            return true;
        }
        if(checksum(root->right, sum,targetSum)){
           return true;
        }
        sum -= root->val;
        return false;
    }

};