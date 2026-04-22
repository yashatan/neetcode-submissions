class Solution {
public:
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        for (int i =0; i < points.size(); i++){
            maxHeap.push({calculateDistance(points[i][0], points[i][1] ), {points[i][0], points[i][1]}});
        }
        while (k>0) {
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
            k--;
        }
        return res;
    }

    int calculateDistance(int x, int y){
        return 0-((x*x) + (y*y));
    }
};
