class Solution {
   public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int curPosition = 0;
        int curRange = 0;
        int res = 0;

        while (curRange < nums.size() - 1) {
            int nextRange = 0;
            for (int i = curPosition; i <= curRange; i++) {
                nextRange = max(nextRange, i + nums[i]);
            }
            curPosition = curRange + 1;
            curRange = nextRange;
            res++;
        }

        return res;
    }
};
