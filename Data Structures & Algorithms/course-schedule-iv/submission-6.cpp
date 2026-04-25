class Solution {
public:
    unordered_map<int, set<int>> children;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        if (prerequisites.size() ==0){
            return vector<bool> (queries.size(), false);
        }
        unordered_map<int, vector<int>> adj;

        for (int i=0; i < numCourses; i++){
            adj[i] = vector<int>();
            children[i] = set<int>();
        }

        for (auto prere : prerequisites){
            int a = prere[0];
            int b = prere[1];
            adj[a].push_back(b);
        }
        
        unordered_set<int> visited;


        for (int i=0; i < numCourses; i++){
            dfs(i, adj, visited, children[i]);
        }
        vector<bool> res;

        for(auto querie : queries){
            int first = querie[0];
            int second = querie[1];
            if (children[first].count(second) >0){
               res.push_back(true);
            }else{
                res.push_back(false);
            }

        }
        return res;
    }

    void dfs(int src, unordered_map<int, vector<int>>& adj, unordered_set<int>& visit, set<int>& childrens){
        if (visit.count(src) > 0) {
           return;
        }

        visit.insert(src);
        for (int neighbor : adj[src]) {
            childrens.insert(neighbor);
            dfs(neighbor, adj, visit, children[neighbor]);
            for(int childrenes : children[neighbor]){
                childrens.insert(childrenes);
            }
        }
    }
};