class Solution {
public:
    int res =0;
    int change(int amount, vector<int>& coins) {
        
        if (amount == 0) return 1;

        vector<int> dp(amount+1, 0);
        for(int i =0; i<= amount; i++){
            if (i%coins[0] ==0){
                dp[i] = 1;
            }
        
        }
        for(int i =0; i<= amount; i++){
            cout << " " << dp[i];
        }

        cout << endl;
        for(int j =1; j<coins.size();j++){
            vector<int> curRow(amount+1,0);
            curRow[0] = 1;
            for(int i = 1; i<= amount; i++){
                int inlinevalue =0;
                if (i < coins[j]){
                    inlinevalue = 0;
                }else{
                    inlinevalue = curRow[i-coins[j]];
                }
                
                curRow[i] = inlinevalue + dp[i];
            }
            dp = curRow;

        }

        return dp[amount];
    }
    // bool dfs(int amount,vector<int> coins, int curSum, int startIndex){

    //     cout << "curSum: " << curSum << endl;
    //     if (curSum == amount){
    //         res++;
    //         cout << "-------OK-----" <<endl;
    //         return false;
    //     }

    //     if(curSum > amount){
    //                 cout << "----return-----" <<endl;
    //         return false;
    //     }

    //     for(int i = startIndex; i < coins.size(); i++){
    //         cout << "coin: " << coins[i] <<endl;
    //         if (dfs(amount, coins, curSum + coins[i], i) == false){
    //             break;
    //         }
    //     }
    //     return true;
    // }

};
