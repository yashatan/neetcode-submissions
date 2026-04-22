class Solution {
public:

    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum(nums.size(),0);
        vector<int> postfixSum(nums.size(),0);
        int preCurSum =0;
        int postCurSum =0;
        for (int i =0; i < nums.size(); i ++){
            preCurSum += nums[i];
            prefixSum[i] = preCurSum;

            postCurSum += nums[nums.size()-i-1];
            postfixSum[nums.size()-i-1] = postCurSum;
        }


        int L = 0;
        int R = nums.size()-1;

        if (postfixSum[1] == 0) return 0;
        if (prefixSum[nums.size()-2] == 0) return nums.size()-1;
        for (int i =1 ; i < nums.size()-2; i++){
            if (prefixSum[i] == postfixSum[i+2]){
                return i+1;
            }
        }

        return -1;
    }
};