class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xortemp =0 ;
        for (int i =1; i <= n; i++){
            xortemp = i ^ xortemp;
        }


        int xortemp2 = nums[0];
        for (int i =1; i < nums.size(); i++){
            xortemp2 = nums[i] ^ xortemp2;
        }

        return xortemp ^ xortemp2;
    }
};
