class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> minCost(cost.size());

        minCost[size-1] = cost[size-1];
        minCost[size-2] = cost[size-2]; 

        for(int i = size-3; i >= 0; i--){
            minCost[i] = cost[i]+min(minCost[i+1], minCost[i+2]);
        }

        return min(minCost[0], minCost[1]);
    }
};
