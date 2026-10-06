class Solution {
   public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        if (size == 2) {
            return max(nums[0], nums[1]);
        }

        if (size == 3) {
            return max(nums[0], max(nums[1], nums[2]));
        }

        if (size == 4) {
            return max(nums[0] + nums[2], nums[1] + nums[3]);
        }

        vector<int> dp(size, 0);
        dp[2] = nums[2];
        dp[1] = nums[1];

        int curMax = max(dp[1], dp[2]);

        vector<int> dp1(size, 0);
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        dp1[2] = nums[0] + nums[2];
        int curMax1 = max(dp1[1], dp1[2]);

        for (int i = 3; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
            curMax = max(curMax, dp[i]);
        }

        for (int i = 3; i < size - 1; i++) {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 3] + nums[i]);
            curMax1 = max(curMax1, dp1[i]);
        }

        curMax = max(curMax, curMax1);

        return curMax;
    }
};
