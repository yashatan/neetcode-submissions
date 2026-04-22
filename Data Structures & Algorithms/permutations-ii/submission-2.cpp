class Solution {
public:
    unordered_map<int, int> numsMap;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> perm;
        for (auto n: nums){
            numsMap[n]++;
        }

        dfs(perm, nums);

        return res;
    }

    void dfs(vector<int>& perm, vector<int>& nums){
        if (perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(auto& [key, value] : numsMap){
            if(value > 0){
                perm.push_back(key);
                value--;
                dfs(perm, nums);
                perm.pop_back();
                value++;
            }
        }
    }
};