class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size()*2);
        int length = nums.size();
        for (int i =0; i< nums.size();i++){
            ans[i] = ans[i+length] = nums[i];
        }
        return ans;
    }
};