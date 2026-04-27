class Solution {
public:
    bool res =false;
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for (auto num:nums){
            sum+=num;
        }

        if (sum%2 ==1) return false;
        sum = sum/2;
        dfs(0, nums, 0, sum);
        return res;
    }

    void dfs(int i, vector<int> nums, int curSum, int target){
        if (res == true) return;
        if (i > nums.size()){
            return;
        }
        curSum += nums[i];
        
        if(curSum == target) {res = true; return;}

        if(curSum > target) {
            curSum -= nums[i];
            dfs(i+1, nums, curSum, target);
            return;
        }

        dfs(i+1, nums, curSum, target);
        curSum -= nums[i];
        dfs(i+1, nums, curSum, target);
    }
};
