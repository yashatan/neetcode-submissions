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
        while (cur->left) {
            stackn.push(cur);
            cur = cur->left;
        }
        // cur = stackn.top();
        // stackn.pop();
    }
    
    int next() {
        int res = 0;
        if(firstFlag == true){
            firstFlag = false;
            res = cur -> val;
            if (stackn.size()>0){
                cur = stackn.top();
                stackn.pop();
            }else if(cur->right){
                cur = cur->right;
                goToMostLeft();
            }
            lastValue = res;
            return res;
        }


        if(cur == nullptr && !stackn.empty()){
            cur = stackn.top();
            stackn.pop();
            res = cur->val;
        }else{
            res = cur->val;
        }

        if(!stackn.empty() || cur->right){
            cur = cur->right;
            goToMostLeft();
        } 

        lastValue = res;
        return res;
    }
    
    void goToMostLeft(){
        if(cur){
            while (cur->left) {
                stackn.push(cur);
                //cout << "stackn2 " <<stackn.size() << endl;
                cur = cur->left;
            }
        }
    }

    bool hasNext() {
        if (stackn.empty()){
            cout << "false1 " << endl;
            cout << cur -> val << endl;
            if (!cur->right){
                cout << "false2 " << endl;
                cout << cur -> val << endl;
                if(lastValue == cur->val)
                return false;
            }

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