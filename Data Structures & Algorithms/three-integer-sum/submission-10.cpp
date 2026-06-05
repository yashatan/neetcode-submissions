class Solution {
   public:
    vector<vector<int>> res;
    set<tuple<int, int, int>> memo;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            dfs(i, i + 1, (int)nums.size() - 1, nums);
        }
        return res;
    }

    void dfs(int L, int M, int R, vector<int>& nums) {
        if (nums[L] > 0) {
            return;
        }

        if (M >= R) {
            return;
        }

        if (memo.count({nums[L], nums[M], nums[R]})) {
            return;
        }

        if (nums[L] + nums[M] + nums[R] == 0) {
            res.push_back(vector<int>({nums[L], nums[M], nums[R]}));
            memo.insert({nums[L], nums[M], nums[R]});

            M++;
            while (M < R && nums[M] == nums[M-1]) {
                M++;
            }
            dfs(L, M + 1, R - 1, nums);
        }

        if (nums[L] + nums[M] + nums[R] > 0) {
            dfs(L, M, R - 1, nums);
        }

        if (nums[L] + nums[M] + nums[R] < 0) {
            dfs(L, M + 1, R, nums);
        }
    }
};