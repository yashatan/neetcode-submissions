class Solution {
public:
    priority_queue<pair<int, int>> maxHeap;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        for (int i =0; i < points.size(); i++){
            maxHeap.push({calculateDistance(points[i][0], points[i][1] ), i});
            if (maxHeap.size() > k)  maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            int index = maxHeap.top().second;
            res.push_back(points[index]);
            maxHeap.pop();
        }
        return res;
    }

    int calculateDistance(int x, int y){
        return ((x*x) + (y*y));
    }
};
