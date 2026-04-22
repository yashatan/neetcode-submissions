class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i =1; i < n+1; i++){
            adj[i] = vector<pair<int, int>>();
        }

        for( auto time: times){
            int s = time[0], d = time[1], w = time[2];
            cout << "s = " << s << " d= " << d << " w= " <<w<<endl;
            adj[s].push_back(make_pair(d, w));
            cout << "size " << adj[1].size() <<endl;
        }

        unordered_map<int, int> shortest;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        //shortest[k] =0;

        minHeap.push({0,k});

        while(!minHeap.empty()){
            pair<int, int> shortRound = minHeap.top();
            minHeap.pop();
            int w1 = shortRound.first;
            int n1 = shortRound.second;
            if(shortest.count(n1) > 0){
                continue;
            }
            shortest[n1] = w1;
            for(pair<int, int> p : adj[n1]){
                int n2 = p.first;
                int w2 = p.second;

                if(shortest.count(n2)==0){
                    minHeap.push({w1+w2, n2});
                }

            }
        }
        int res =0;
        for(int i = 1; i<n+1; i++){
            if(shortest.count(i) ==0 ){
                cout << "i " << i << endl;
                
                res = -1;
                break;
            }else{
                res = max(res, shortest[i]);
            }
        }

        return res;

    }
};
