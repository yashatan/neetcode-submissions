class Solution {
public:
    vector<vector<int>> memo;
    int res=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        memo = vector<vector<int>>(1<<nums.size(), vector<int>(nums.size(),-1));
        int mask = 0;
        dfs(0, 0, nums, target);
        dfs(0, 1, nums, target);
        return res;
    }

    void dfs(int index, int mask, vector<int> nums, int target){


        int curSum = 0;
        if (index == 0){
            memo[0][index] = -nums[0];
            memo[1][index] = nums[0];
        }else{

            int lastSum = memo[ mask & ((1<<(index))-1)][index-1];
            if(mask >> index & 0x1){
                memo[mask][index] = lastSum + nums[index];
            }else{
                memo[mask][index] = lastSum - nums[index];
            }

        }
        if (index == nums.size()-1){
            if(target == memo[mask][index]) res++;
            return;
        }


        dfs(index+1, mask + (0 << (index+1)), nums, target);
        dfs(index+1, mask + (1 << (index+1)), nums, target);
    }
    
};
