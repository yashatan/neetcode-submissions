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
        TreeNode* root = new TreeNode(preorder[0]);
        int rootindex_indorder = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> inoderleft(inorder.begin(), inorder.begin()+rootindex_indorder); 
        vector<int> preorderleft(preorder.begin()+1, preorder.begin()+rootindex_indorder+1);


        vector<int> inorderright (inorder.begin()+rootindex_indorder+1, inorder.end()); 
        vector<int> preorderright (preorder.begin()+rootindex_indorder+1, preorder.end());

        root->left = buildTree(preorderleft, inoderleft);
        root->right = buildTree(preorderright, inorderright);
        return root;

    }
};
