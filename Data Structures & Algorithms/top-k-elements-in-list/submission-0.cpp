class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (auto num : nums) {
            mp[num]++;
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;  // max heap by value
            };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (auto p : mp) {
            pq.push(p);
        }

        while (k > 0) {
            auto p = pq.top();
            res.push_back(p.first);
            pq.pop();
            k--;
        }

        return res;
    }
};