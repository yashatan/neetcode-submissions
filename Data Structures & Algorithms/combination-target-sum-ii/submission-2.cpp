class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curComb;
        calculate(0, 0, curComb, candidates, target);
        return res;
    }

    void calculate(int i, int cursum, vector<int>& curComb, vector<int>& candidates, int target) {
        if (target == cursum) {
            res.push_back(curComb);
            return;
        }
        if (i >= candidates.size()) {
            return;
        }

        if (cursum > target) {
            return;
        }

        curComb.push_back(candidates[i]);
        calculate(i + 1, cursum + candidates[i], curComb, candidates, target);
        curComb.pop_back();
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }
        calculate(i + 1, cursum, curComb, candidates, target);
    }

};
