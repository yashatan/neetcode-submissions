class Solution {
public:
        unordered_map<int, vector<int>> edgeMap;
        unordered_set<int> visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        for(int i=0; i< prerequisites.size(); i++){
            edgeMap[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i=0; i< numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int course){
        if(!edgeMap.count(course)){
            return true;
        }


        if (visit.count(course)){
            return false;
        }

        visit.insert(course);
        for (int i =0; i < edgeMap[course].size(); i++){
            if(!dfs(edgeMap[course][i])){
                return false;
            }
        }
        visit.erase(course);
       //  edgeMap[course].clear();
        return true;

    }
};
