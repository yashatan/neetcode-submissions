class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int, int, int>>> minHeap; 
        int res =0;

        for(int i =1; i< points.size();i++){
            int distance = fabs(points[i][0]-points[0][0]) +fabs(points[i][1]-points[0][1]); 
            minHeap.push({distance, 0, i});
        }

        unordered_set<int> visit;
        visit.insert(0);

        while(visit.size() < points.size()){
            tuple<int, int, int> cur = minHeap.top();
            minHeap.pop();
            int w1 = get<0>(cur), n1 = get<1>(cur), n2 = get<2>(cur);

            if (visit.count(n2) > 0) {
                continue;
            }
            
            visit.insert(n2);
            res += w1;
            for (int j =0; j < points.size(); j++) {
                if (j == n2 || visit.count(j)){
                    continue;
                }
                int distance = fabs(points[j][0]-points[n2][0]) +fabs(points[j][1]-points[n2][1]); 
                minHeap.push({distance, n2, j});

            }
        }
        return res;
    }
};
