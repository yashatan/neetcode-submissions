/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> oldNewMap;
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }

    Node* dfs(Node* node){
        if(!node){
            return nullptr;
        }

        if(oldNewMap.count(node)){
           return oldNewMap[node];
        }

        Node* newnode = new Node(node->val);
        oldNewMap[node] = newnode;

        for(int i=0; i < node->neighbors.size(); i++){
            newnode->neighbors.push_back(dfs(node->neighbors[i]));
        }

        return newnode;
    }
};
