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
    int curRes = INT_MIN;
    int maxPathSum(TreeNode* root) {
        curRes = root->val;
       dfs(root);
       return curRes;
    }

    int dfs(TreeNode* cur){
        if(!cur){
            return 0;
        }

        int leftMax = max(dfs(cur->left),0);
        int rightMax = max(dfs(cur->right),0);

        int curVal = cur->val + leftMax + rightMax;
        curRes = max(curRes, curVal);

        return cur->val + max(leftMax, rightMax);

    }
};
