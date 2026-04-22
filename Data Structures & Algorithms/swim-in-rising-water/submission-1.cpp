class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;

        minHeap.push({grid[0][0], {0,0}});
        map<pair<int, int>, int> shortest;
        while(minHeap.size() >0){
            pair<int,pair<int,int>> shortLocal = minHeap.top();
            minHeap.pop();
            int w1 = shortLocal.first;
            pair<int,int> n1 = shortLocal.second;
            if (shortest.count(n1)){
                continue;
            }
            cout << "row: " << n1.first << " col: " << n1.second << endl;
            cout << "w1: " << w1 << endl;
            
            shortest[n1] = w1;
            if(n1.first>0){
                int w2 = grid[n1.first-1][n1.second];
                cout << "lên w2: " << w2 << endl;
                minHeap.push({max(w1,w2),{n1.first-1, n1.second}});
            }
            if(n1.first < grid.size()-1){
                int w2 = grid[n1.first+1][n1.second];
                cout << "xuong w2: " << w2 << endl;
                minHeap.push({max(w1,w2),{n1.first+1, n1.second}});
            }
            if(n1.second > 0){
                int w2 = grid[n1.first][n1.second-1];
                cout << "trái w2: " << w2 << endl;
                minHeap.push({max(w1,w2),{n1.first, n1.second-1}});
            }
            if(n1.second < grid.size()-1){
                int w2 = grid[n1.first][n1.second+1];
                cout << "phải w2: " << w2 << endl;
                minHeap.push({max(w1,w2),{n1.first, n1.second+1}});
            }
        }
        return shortest[{grid.size()-1,grid.size()-1}];
    }
};
