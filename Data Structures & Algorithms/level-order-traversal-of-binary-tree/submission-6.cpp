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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> res;
        
        if(!root){
            return res;
        }  

        int level =0;
        nodeQueue.push(root);


        while(!nodeQueue.empty()){
            vector<int> sublist;
            int length = nodeQueue.size();
           for(int i =0; i < length; i++) {
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                sublist.push_back(cur->val);
                if(cur->left){
                    nodeQueue.push(cur->left);
                }

                if (cur->right){
                    nodeQueue.push(cur->right);
                }
            }
            res.push_back(sublist);
            level++;
        }
return res;

    }
};
