class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        set<vector<int>> permMap;
        for(auto n : nums){
            vector<vector<int>> nextPerms;
            for(auto p : perms){
                for (int i =0; i < p.size()+1;i ++){
                    vector<int> xCopy(p);
                    xCopy.insert(xCopy.begin() + i,n);

                    if(!permMap.count(xCopy)){
                                            nextPerms.push_back(xCopy);
                                            permMap.insert(xCopy);
                    }
                }
            }
            perms = nextPerms;
        }

        return perms;
    }
};