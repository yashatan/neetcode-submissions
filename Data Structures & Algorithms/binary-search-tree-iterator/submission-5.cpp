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
class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> stackn;
    bool firstFlag= true;
    int lastValue = 0;
    BSTIterator(TreeNode* root) {
        cur = root;
        goToMostLeft(); 
    }
    
    int next() {
        if(firstFlag == true){
            firstFlag = false;
            lastValue = cur -> val;
            if (stackn.size()>0){
                cur = stackn.top();
                stackn.pop();
            }else if(cur->right){
                cur = cur->right;
                goToMostLeft();
            }
            return lastValue;
        }


        if(cur == nullptr && !stackn.empty()){
            cur = stackn.top();
            stackn.pop();
            lastValue = cur->val;
        }else{
            lastValue = cur->val;
        }

        if(!stackn.empty() || cur->right){
            cur = cur->right;
            goToMostLeft();
        } 

        return lastValue;
    }
    
    void goToMostLeft(){
        if(cur){
            while (cur->left) {
                stackn.push(cur);
                cur = cur->left;
            }
        }
    }

    bool hasNext() {
        if (stackn.empty() && !cur->right && lastValue == cur->val){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */