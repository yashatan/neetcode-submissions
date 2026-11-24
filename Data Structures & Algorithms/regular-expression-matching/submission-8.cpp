class Solution {
   public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        dp.assign(s.length() + 1, vector<int>(p.length() + 1, -1));
        return dfs(0, 0, s, p);
    }

    bool dfs(int i, int j, const string& s, const string& p) {
        if (i >= s.length() && j >= p.length()) {
            return true;
        }

        if (j >= p.length()) {
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = (i < s.length() && ((s[i] == p[j]) || (p[j] == '.')));

        if ((j + 1 < p.length()) && p[j + 1] == '*') {
            dp[i][j] = (dfs(i, j + 2, s, p) || (match && dfs(i + 1, j, s, p)));
        }

        else if (match) {
            dp[i][j] = dfs(i + 1, j + 1, s, p);
        } else {
            dp[i][j] = false;
        }
        return dp[i][j];
    }
};
