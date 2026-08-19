class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 0; i < intervals.size(); i++) {
            checkAndMerge(res, intervals[i]);
        }

        return res;
    }

    void checkAndMerge(vector<vector<int>>& res, vector<int>& interval2) {
        vector<int>& interval1 = res[res.size() - 1];
        if (interval1[0] > interval2[1]) {
            res.insert(res.end() - 1, interval2);
            return;
        }

        if (interval1[1] < interval2[0]) {
            res.push_back(interval2);
            return;
        }

        interval1[0] = min(interval1[0], interval2[0]);
        interval1[1] = max(interval1[1], interval2[1]);
    }
};
