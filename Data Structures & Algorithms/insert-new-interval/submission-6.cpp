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
            if (intervals[0][0] < newInterval[0]) {
                res.push_back(intervals[0]);
                checkAndMerge(res, newInterval);
            } else {
                res.push_back(newInterval);
                checkAndMerge(res, intervals[0]);
            }
            return res;
        }
        // find pivot
        int pivot = 0;

        vector<vector<int>> res;
        while ((pivot < intervals.size()) && intervals[pivot][0] < newInterval[0] ) {
            pivot++;
        }

        if(pivot == 0){
            res.push_back(newInterval);
        }
        if(pivot == intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        for (int i = 0; i < pivot; i++) {
            res.push_back(intervals[i]);
        }

        checkAndMerge(res, newInterval);

        for (int i = pivot; i < intervals.size(); i++) {
            checkAndMerge(res, intervals[i]);
        }

        return res;
    }

    void checkAndMerge(vector<vector<int>>& res, vector<int>& interval2) {
        vector<int> interval1 = res[res.size() - 1];
        if (interval1[1] >= interval2[0]) {
            interval1[1] = max(interval1[1],interval2[1]) ;
            res.pop_back();
            res.push_back(interval1);
        } else {
            res.push_back(interval2);
        }
    }
};
