class Solution {
public:
    int minDistance(string word1, string word2) {
        int res =0;
        vector<int> dp (word1.length(), 0);
        bool initFoundWord = false;

        if (word1.length() ==0 || word2.length()==0){
            return max(word1.length(),word2.length());
        }

        if(word1[0] == word2[0]){
            dp[0] = 0;
            initFoundWord = true;
        }else{
            dp[0] = 1;
        }


        for (int initi =1; initi < dp.size(); initi++){
            if(word1[initi] == word2[0] && !initFoundWord){
                dp[initi] = dp[initi-1];
                initFoundWord= true;
            }else{
                dp[initi] = dp[initi-1]+1;
            }
        }

        for(int i2 = 1; i2 < word2.size(); i2++){
            vector<int> curRow (word1.length(), 0);
            if(word1[0] == word2[i2]){
                curRow[0] = dp[0];
            }else{
                curRow[0] = dp[0]+1;
            }
                for(int i1 = 1; i1 < word1.size(); i1++){
                    if(word1[i1] == word2[i2]){
                        curRow[i1] = dp[i1-1];
                    }else{
                        curRow[i1] = min({dp[i1]+1, curRow[i1-1]+1, dp[i1-1]+1});
                    }
                }
            
            dp = curRow;
        }

        return dp[word1.size()-1];
    }
};
