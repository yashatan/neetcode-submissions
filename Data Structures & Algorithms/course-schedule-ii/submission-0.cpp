class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (int i=0; i < numCourses; i++){
            adj[i] = vector<int>();
        }

        for (auto prere : prerequisites){
            int a = prere[0];
            int b = prere[1];
            adj[a].push_back(b);
        }

        unordered_set<int> visited;
        unordered_set<int> path;

        vector<int> topsort;

        for (int i=0; i < numCourses; i++){
            if(dfs(i, adj, visited, topsort, path)==-1){
                return vector<int>();
            }        
        }
        return topsort;

    }

    int dfs(int src, unordered_map<int, vector<int>>& adj, unordered_set<int>& visit, vector<int>& topSort, unordered_set<int>& path){
        if (path.count(src) > 0) {
           return -1;
        }

        if (visit.count(src) > 0) {
           return 0;
        }
        cout << "src: " << src << endl;

        visit.insert(src);
        path.insert(src);
        for (int neighbor : adj[src]) {
           if (dfs(neighbor, adj, visit, topSort, path)==-1) return -1;
        }

        topSort.push_back(src);
        path.erase(src);
        return 0;
    }
};
