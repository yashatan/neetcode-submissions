class LRUCache {
public:
    int mcapacity;
    unordered_map<int, int> useStack;
    unordered_map<int, int> mainSet;
    LRUCache(int capacity) {

        mcapacity = capacity;
    }
    
    int get(int key) {
        if(mainSet.count(key)){
            cout << "get " << key << " value " << mainSet[key] <<endl;
            for(auto it = useStack.begin(); it != useStack.end(); it++){
                it->second++;
            }
            useStack[key] =0;
            return mainSet[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        
        if(mainSet.count(key)){
            mainSet[key] =value;
            for(auto it = useStack.begin(); it != useStack.end(); it++){
                it->second++;
            }
            useStack[key] =0;
        }else{
             if (mainSet.size() < mcapacity){
                mainSet.insert({key, value});
                cout << "added " << key << " value " << value <<endl;
                for(auto it = useStack.begin(); it != useStack.end(); it++){
                    it->second++;
                }
                useStack.insert({key, 0});
             }else{
                auto max_it = std::max_element(
                useStack.begin(), 
                useStack.end(), 
                [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.second < p2.second;
               }
            );
                cout << "erase " << max_it->first << " value " << mainSet[max_it->first] <<endl;
                mainSet.erase(max_it->first);
                useStack.erase(max_it);
                mainSet.insert({key, value});
                
                for(auto it = useStack.begin(); it != useStack.end(); it++){
                    it->second++;
                }
                useStack.insert({key, 0});
                cout << "added " << key << " value " << value <<endl;
             }
        }
    }
};
