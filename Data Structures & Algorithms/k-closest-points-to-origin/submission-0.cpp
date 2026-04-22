class Solution {
public:
    priority_queue<float> pq;
    vector<float> distancemap;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        for (int i =0; i < points.size(); i++){
            pq.push(calculateDistance(points[i][0],points[i][1]));
            distancemap.push_back(calculateDistance(points[i][0],points[i][1]));
        }
        for (int i = 0; i < k; i++){
            // res.add(pq.top());
            for (int j=0; j < points.size(); j++){
                if (distancemap[j] == pq.top()){
                                        res.push_back(points[j]);
                    distancemap.erase(distancemap.begin()+j);
                    points.erase(points.begin()+j);

                    break;
                }
            }
            pq.pop();
        }

        return res;
    }

    float calculateDistance(int x, int y){
        return 0-sqrt((float)(x*x) + (float)(y*y));
    }
};
