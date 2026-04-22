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
        cout << "--------added " << word << " -------" << endl;
    }
    
    bool search(string word) {
        TrieNode* cur = &root;
        int temp = searchdfs(cur, word, 0);
        cout << "--------return search ---------- "  << temp << endl;
        return  temp;
    }

    bool searchdfs(TrieNode* node, string word, int index){
        cout<< "searchdfs" << endl;
        bool res = false;
        if(index == word.length()){
            cout << "return fisrt base case true"  << node->word << endl;
            return node->word;
        }

        if(!node){
            cout << "return second base case false" << endl;
            return false;
        }
            
        char c = word[index];
        cout<< "Current search word: " << word << endl;
        cout<< "Current search char: " << c << endl;
        if(c == '.'){
            if(node->children.size() ==0){
                cout << "return third base case false" << endl;
                return false;
            }

            for (auto pairs : node->children) {
                res = searchdfs(pairs.second, word, index+1);
                if (res == true) break;
            }
        }else{
            if (node->children.count(c)==0){
                cout << "return fourth base case false" << endl;
                return false;
            }
            cout << "dfs without ." << endl;          
            res = searchdfs(node->children[c], word, index+1);
        }
        return res;
    }
};
