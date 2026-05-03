class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end(), std::greater<int>());
        vector<int> dp(amount+1, INT_MAX);
        dp[0] =0;
        for (int a=coins[0]; a <= amount; a += coins[0]){
            dp[a] = dp[a-coins[0]] + 1;
        }
        for(int i =1; i< coins.size(); i++){
            vector<int> curRow(amount+1, INT_MAX);
            int curCoin = coins[i];
            for(int a = 0; a<= amount; a++){
                if(curCoin > a){
                    curRow[a] = dp[a];
                    continue;
                }
                
                if( a >= curCoin){
                    int skip = dp[a];
                    int include = skip;
                    if (curRow[a-curCoin] != INT_MAX){
                        include = curRow[a-curCoin] + 1;
                    }
                    curRow[a] = min(include, skip);
                }
            }
            dp = curRow;
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};


