class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int L =0, R = 1;

        int res = 0;
        while (R < prices.size()) {
            if(prices[R]-prices[L] <= 0){
                L=R;
            }else{
                int temp = prices[R]-prices[L];
                res = max(res, temp);
            }
            R++;
        }
        return res;
    }   
};
