class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, target, 0, res, cur);
        return res;
    }


    void dfs(vector<int>& nums,int target, int i, vector<vector<int>>& res, vector<int>& cur){

        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(i == nums.size() || target < 0){
            return;
        }

        cur.push_back(nums[i]);
        dfs(nums, target -nums[i] , i, res, cur);
        cur.pop_back();
        dfs(nums, target, i+1, res, cur);
    }
};
 