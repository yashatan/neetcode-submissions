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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode * cur = root;
        stack<TreeNode*> nodeStack;

        while(cur || !nodeStack.empty()){
            if(cur){
                res.push_back(cur->val);
                nodeStack.push(cur->right);
                cur = cur->left;

            }else{
                cur = nodeStack.top();
                nodeStack.pop();
            }
        }
        return res;
    }
};