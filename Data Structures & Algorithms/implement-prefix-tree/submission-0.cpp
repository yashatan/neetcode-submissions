class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;
};

class PrefixTree {
public:
    TrieNode root;
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode* cur = &root;
        for(char c:word){
            if (cur->children.count(c)==0){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        TrieNode* cur = &root;
        for(char c:word){
            if (cur->children.count(c)==0){
                return false;
            }
            cur = cur->children[c];
        }
        return cur->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = &root;
        for(char c:prefix){
            if (cur->children.count(c)==0){
                return false;
            }
            cur = cur->children[c];
        }
        return true;
    }
};
