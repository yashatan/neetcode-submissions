class Solution {
public:
    vector<vector<int>> cache;
    int longestCommonSubsequence(string text1, string text2) {
        cache = vector<vector<int>> (text1.size(), vector<int>(text2.size(),0));
        return dfs(text1, text2, 0, 0);
    }

private:
    int dfs(const string& text1, const string& text2, int i, int j) {

        if (i == text1.size() || j == text2.size()) {
            return 0;
        }


        if(cache[i][j] !=0){
            return cache[i][j];
        }


        if (text1[i] == text2[j]) {
            cache[i][j] =  1 + dfs(text1, text2, i + 1, j + 1);
        } else{
        cache[i][j] = max(dfs(text1, text2, i + 1, j),
                   dfs(text1, text2, i, j + 1));
        }

        return cache[i][j];
    }
};