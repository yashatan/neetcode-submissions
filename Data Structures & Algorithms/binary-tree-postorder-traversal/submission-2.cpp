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
    vector<int> postorderTraversal(TreeNode* root) {
            vector<TreeNode*> stackn = {root};
    vector<bool> visit = {false};
    vector<int> res;
    while (stackn.size()) {
        TreeNode* curr = stackn.back();
        bool visited = visit.back();
        stackn.pop_back();
        visit.pop_back();
        if (curr) {
            if (visited) {
                res.push_back(curr->val);
            } else {
                stackn.push_back(curr);
                visit.push_back(true);
                stackn.push_back(curr->right);
                visit.push_back(false);
                stackn.push_back(curr->left);
                visit.push_back(false);
            }
        }
    }
    return res;
    }
};