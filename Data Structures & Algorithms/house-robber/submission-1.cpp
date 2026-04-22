class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxArr(nums.size(),0);
        maxArr[0] = nums[0];
        maxArr[1] = nums[1];
        maxArr[2] = nums[2]+nums[0];

        for(int i=3;i< maxArr.size(); i++){
            maxArr[i] = nums[i] + max(maxArr[i-2], maxArr[i-3]);
        }
        
        return max(maxArr[nums.size()-1], maxArr[nums.size()-2]);
    }
};
