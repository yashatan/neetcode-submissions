class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};

        for(auto n : nums){
            vector<vector<int>> nextPerms;
            for(auto p : perms){
                for (int i =0; i < p.size()+1;i ++){
                    vector<int> xCopy(p);
                    xCopy.insert(xCopy.begin() + i,n);
                    nextPerms.push_back(xCopy);
                }
            }
            perms = nextPerms;
        }

        return perms;
    }
};
