class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        // vector<int> minCost(cost.size());

        // minCost[size-1] = cost[size-1];
        // minCost[size-2] = cost[size-2]; 

        for(int i = size-3; i >= 0; i--){
            cost[i] = cost[i]+min(cost[i+1], cost[i+2]);
        }

        return min(cost[0], cost[1]);
    }
};
