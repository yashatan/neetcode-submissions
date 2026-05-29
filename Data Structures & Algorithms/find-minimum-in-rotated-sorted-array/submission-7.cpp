class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        return dfs(0, nums.size(), nums);
    }

    int dfs(int L, int R, vector<int>& nums) {

        int mid = (L + R) / 2;
        if (mid == 0 || mid == nums.size() - 1) {
            return min(nums[0], nums[nums.size() - 1]);
        }

        if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
            return nums[mid];
        }

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return nums[mid+1];
        }

        if (nums[0] > nums[mid]) {
            return dfs(L, mid, nums);
        }
        else {
            return dfs(mid, R, nums);
        }

        return 0;
    }
};