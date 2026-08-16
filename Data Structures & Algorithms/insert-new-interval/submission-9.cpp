class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // corner case
        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (intervals.size() == 1) {
            vector<vector<int>> res;
            res.push_back(intervals[0]);
            checkAndMerge(res, newInterval);
            return res;
        }

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int pivot = intervals.size();
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else {
                checkAndMerge(res, newInterval);
                pivot = i;
                break;
            }
        }
        if (pivot == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        for (int i = pivot; i < intervals.size(); i++) {
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
