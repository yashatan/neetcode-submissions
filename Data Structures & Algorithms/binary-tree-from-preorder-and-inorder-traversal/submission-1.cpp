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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()){
            return nullptr;
        }
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int rootindex_indorder =0;
        while(inorder[rootindex_indorder] != rootVal){
            rootindex_indorder++;
        }
        vector<int> inoderleft(inorder.begin(), inorder.begin()+rootindex_indorder); 
        vector<int> preorderleft(preorder.begin()+1, preorder.begin()+rootindex_indorder+1);


        vector<int> inorderright (inorder.begin()+rootindex_indorder+1, inorder.end()); 
        vector<int> preorderright (preorder.begin()+rootindex_indorder+1, preorder.end());

        root->left = buildTree(preorderleft, inoderleft);
        root->right = buildTree(preorderright, inorderright);
        return root;

    }
};
