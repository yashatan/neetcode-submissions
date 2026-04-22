class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>, vector<pair<double,int>>> maxHeap; 
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i =1; i < n+1; i++){
            adj[i] = vector<pair<int, double>>();
        }

        for( int i =0; i < edges.size(); i++){
            vector<int> edge = edges[i];
            int s = edge[0];
            int d = edge[1];
            double prop = succProb[i];
            adj[s].push_back(make_pair(d, prop));
            adj[d].push_back(make_pair(s, prop));
        }

        maxHeap.push({1.0, start_node});

        unordered_map<int, double> highest;

        while(!maxHeap.empty()){
            pair<double, int> shortRound = maxHeap.top();
            maxHeap.pop();
            double p1 = shortRound.first;
            int n1 = shortRound.second;
            cout << "n1 " << n1 << endl;

            if (n1 == end_node) return p1;

            if(highest.count(n1) > 0){
                continue;
            }

            highest[n1] = p1;

            for(pair<int, double> p : adj[n1]){
                int n2 = p.first;
                double p2 = p.second;
                cout << "n2 " << n2 << " p2 " << p2 << endl;
                if(highest.count(n2)==0){
                    maxHeap.push({p1*p2, n2});
                }

            }
        }

        double res =0.0;
        if(highest.count(end_node)) res = highest[end_node];

        return res;
    }
};