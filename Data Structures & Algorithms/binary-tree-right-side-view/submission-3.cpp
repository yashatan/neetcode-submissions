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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<int> res;
        
        if(!root){
            return res;
        }  

        int level =0;
        nodeQueue.push(root);


        while(!nodeQueue.empty()){
            int length = nodeQueue.size();
            for(int i =0; i < length; i++) {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                if (i == 0) res.push_back(cur->val);
                
                if (cur->right){
                    nodeQueue.push(cur->right);
                }
                if(cur->left){
                    nodeQueue.push(cur->left);
                }
            }
            level++;
        }
        return res;

    }
};
