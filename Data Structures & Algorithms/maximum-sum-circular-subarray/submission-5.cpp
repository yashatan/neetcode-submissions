class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res =INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            res = max(res, maxSubArray(nums, i, nums.size()));
        }
        return res;
    }

    int maxSubArray(vector<int>& nums, int s, int length) {
        int maxRes = nums[s];
        int curMax = 0;
        int index =s;
        while(index != (length+s)){
            curMax = max(curMax, 0);
            curMax += nums[index%length];
            maxRes = max(maxRes, curMax);
            index++;
        }
        return maxRes;
    }
};