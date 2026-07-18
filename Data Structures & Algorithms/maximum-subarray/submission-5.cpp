class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxRes = nums[0];
        int curMax = 0;

        for(int num : nums){
            curMax = max(num, curMax+num);
            maxRes = max(maxRes, curMax);
        }
        return maxRes;
    }
};
