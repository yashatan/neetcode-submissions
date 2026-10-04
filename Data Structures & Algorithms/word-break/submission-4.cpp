class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        vector<bool> dp(size + 1, false);
        dp[size] = true;

        for (int i = size - 1; i >= 0; i--) {
            for (auto word : wordDict) {
                if (((size - i) >= word.length()) && (s.substr(i, word.length()) == word)) {
                    dp[i] = dp[i + word.length()];
                }
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};
