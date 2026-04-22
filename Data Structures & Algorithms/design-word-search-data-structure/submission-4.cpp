class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool word = false;
};

class WordDictionary {
public:
    TrieNode root;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* cur = &root;
        for (char c : word){
            if(cur->children.count(c) ==0){
                cur->children[c] = new TrieNode();
                cur->children['.'] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        TrieNode* cur = &root;
        int temp = searchdfs(cur, word, 0);
        return  temp;
    }

    bool searchdfs(TrieNode* node, string word, int index){
        bool res = false;
        if(index == word.length()){
            return node->word;
        }

        if(!node){
            return false;
        }
            
        char c = word[index];
        if(c == '.'){
            if(node->children.size() ==0){
                return false;
            }

            for (auto pairs : node->children) {
                res = searchdfs(pairs.second, word, index+1);
                if (res == true) break;
            }
        }else{
            if (node->children.count(c)==0){
                return false;
            }        
            res = searchdfs(node->children[c], word, index+1);
        }
        return res;
    }
};
