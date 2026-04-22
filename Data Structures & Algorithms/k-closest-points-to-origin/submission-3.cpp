class Solution {
public:
    priority_queue<pair<int, int>> maxHeap;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        for (int i =0; i < points.size(); i++){
            maxHeap.push({calculateDistance(points[i][0], points[i][1] ), i});
        }
        while (k>0) {
            int index = maxHeap.top().second;
            res.push_back(points[index]);
            maxHeap.pop();
            k--;
        }
        return res;
    }

    int calculateDistance(int x, int y){
        return 0-((x*x) + (y*y));
    }
};
