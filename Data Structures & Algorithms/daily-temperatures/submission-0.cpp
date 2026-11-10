class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stackdays;
        vector<int> res(temperatures.size(), 0);
        stackdays.push({temperatures[0], 0});
        for (int i = 1; i < temperatures.size(); i++) {
            int val = temperatures[i];
            while (stackdays.size() > 0 && stackdays.top().first < val) {
                res[stackdays.top().second] = i - stackdays.top().second;
                stackdays.pop();
            }
            stackdays.push({val,i});
        }

        return res;
    }
};
