class Solution {   
public:
    vector<vector <int>> dp; 
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length()+s2.length()) return false;
        dp = vector<vector<int>>(s1.length()+1, vector<int>(s2.length()+1,-1));
        bool res = dfs(s1, s2, s3, 0, 0, 0);
        return res;
    }

    bool dfs(string s1, string s2, string s3, int i1, int i2, int i3){
         if (i3 == s3.length()){
            return true;
         }
        char c1 = s1[i1];
        char c2 = s2[i2];
        char c3 = s3[i3];

        if (c3 != c1 && c3 != c2){
            return false;
        }

        if (dp[i1][i2] !=-1){
            return dp[i1][i2];
        }

        if (c3 == c1 && c3 != c2){
            dp[i1][i2] = dfs(s1, s2, s3, i1+1, i2, i3+1);
        }

        if (c3 == c2 && c3 != c1){
            dp[i1][i2] = dfs(s1, s2, s3, i1, i2+1, i3+1);
        }

        if (c3 == c2 && c3 == c1){
            dp[i1][i2] = dfs(s1, s2, s3, i1, i2+1, i3+1) || dfs(s1, s2, s3, i1+1, i2, i3+1);
        }

        return dp[i1][i2];
    }
};
