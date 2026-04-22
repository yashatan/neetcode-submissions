class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lengthRes = INT_MAX;
        int L = 0;
        int curMax = 0;
        int curLength =0;
        bool foundFlag=0;
        for(int R =0; R < nums.size(); R++){
            curMax += nums[R];
            curLength++;
            while(curMax >= target){
                foundFlag = true;
                lengthRes = min(curLength, lengthRes);
                curMax -= nums[L];
                curLength--;
                L++;
            }
        }
        if(foundFlag) return lengthRes;
        return 0;
    }
};