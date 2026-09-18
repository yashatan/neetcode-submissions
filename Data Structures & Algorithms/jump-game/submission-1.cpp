class Solution {
public:
    bool canJump(vector<int>& nums) { return dfs(0, nums); }

    bool dfs(int curPos, vector<int>& nums) {

        if (curPos == nums.size() -1) return true;
        if (nums[curPos] != 0 && nums[curPos] <= nums[curPos + 1]) {
            return dfs(curPos + 1, nums);
        }

        if (nums[curPos] + curPos >= nums.size() - 1) {
            return true;
        }

        if (nums[curPos] == 0 && curPos < nums.size() - 1) {
            return false;
        }



        bool res = false;
        for (int i = 1; i < nums[curPos]+1; i++) {
            if (dfs(curPos + i, nums) == true) return true;
        }

        return res;
    }
};