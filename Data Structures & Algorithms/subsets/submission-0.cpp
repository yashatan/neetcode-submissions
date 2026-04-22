class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int times =1;

        times = (times<<nums.size());

        for(int j = 0; j< times;j++){
            vector<int> subset;
            for(int i = 0; i< nums.size();i++){
                if((j >> (i)) & 0b1){
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }

        return res;
    }
};
