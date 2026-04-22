class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum(nums.size(),0);
        int preCurSum =0;
        for (int i =0; i < nums.size(); i ++){
            preCurSum += nums[i];
            prefixSum[i] = preCurSum;
        }


        int L = 0;
        int R = nums.size()-1;

        if (prefixSum[nums.size()-1] - prefixSum[0] == 0) return 0;
        if (prefixSum[nums.size()-2] == 0) return nums.size()-1;
        for (int i =1 ; i < nums.size()-2; i++){
            if (prefixSum[i] == prefixSum[nums.size()-1]-prefixSum[i+1]){
                return i+1;
            }
        }

        return -1;
    }
};