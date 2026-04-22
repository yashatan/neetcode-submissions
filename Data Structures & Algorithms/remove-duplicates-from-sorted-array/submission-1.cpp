class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int iterator =1;
        while (iterator < nums.size()){
            if (nums[iterator] == nums[iterator-1]){
                nums.erase(nums.begin() + iterator);
            }
            else {
                iterator++;
            }
        }
        return iterator;
    }
};