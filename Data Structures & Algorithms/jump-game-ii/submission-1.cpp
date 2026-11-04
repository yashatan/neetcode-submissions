class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() == 1){
            return 0;
        }
        int curPosition =0;
        int curRange = 0 + nums[0];
        int res = 1;

        while(curRange < nums.size()-1){
            int nextRange = 0;
            int temp = 0;
            for(int i = curPosition + 1 ; i <= curRange; i++){
                if (i + nums[i] > nextRange){
                    nextRange = i + nums[i];
                    temp = i;
                    //cout << i;
                }
                //nextRange = max(nextRange, i + nums[i]);
            }

            curPosition = temp;
            curRange = nextRange;
            res++;
        }

        return res;
    }
};
