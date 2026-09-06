class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return 0;
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        int curEnd = intervals[0][1];
        int res = 0;

        for (int i = 1; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (start >= curEnd) {
                curEnd = end;
            } else {
                res++;
                curEnd = min(end, curEnd);
            }
        }
        return res;
    }
};
