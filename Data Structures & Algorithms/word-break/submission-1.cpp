class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.length();
        vector<bool> dp(size + 1, false);
        dp[size] = true;

        for (int i = size - 1; i >= 0; i--) {
            cout << "i: " << i << endl << endl;
            for (auto word : wordDict) {
                if (i == 5) cout << word << endl;
                if (i == 5) cout << s.substr(i, word.length()) << endl;
                if (i == 5) cout << size - i << endl;
                if (i == 5) cout << word.length() << endl;
                if (((size - i) >= word.length()) && (s.substr(i, word.length()) == word)) {
                    cout << s.substr(i, word.length()) << endl;
                    cout << i << endl;
                    cout <<i + word.length() << endl; 
                    dp[i] = dp[i + word.length()];
                    cout << "true, fasle: "<<dp[i] << endl;
                }
                if (dp[i]) {
                    break;
                }
            }
        }

        return dp[0];
    }
};
