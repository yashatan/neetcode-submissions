class Solution {
public:
	vector<vector<int>> dp;
	int longestPalindromeSubseq(string s) {
		dp = vector<vector<int>>(s.length(), vector<int>(s.length(), -1));
		int curMax = 0;
		for (int i = 0; i < s.length(); i++) {
			curMax = max(curMax, dfs(i, i, s));
            curMax = max(curMax, dfs(i, i+1, s));
		}

		return curMax;
	}


	int dfs(const int L,const int R,const string& s) {
		if (L < 0 || R >= s.length()) {
			return 0;
		}
		if (dp[L][R] != -1) {
			return dp[L][R];
		}

		if (s[L] == s[R]) {
			int temp = L == R ? 0 : 2;
			dp[L][R] = temp + dfs(L - 1, R + 1, s);
		}
		else {
			dp[L][R] = max(dfs(L - 1, R, s), dfs(L, R + 1, s));
		}

		return L==R?dp[L][R]+1:dp[L][R];
	}
};