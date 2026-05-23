class Solution {
public:
	int countSubstrings(string s) {
		int res = 0;
		for (int i = 0; i < s.length(); i++) {
			int quanTemp = dfs(i, i, s);
			res += quanTemp;
		}

		for (int i = 0; i < s.length() - 1; i++) {
			int tempLength = 0;
			int quanTemp = dfs(i, i + 1, s);
			res += quanTemp;
		}
		return res;
	}

	int dfs(int L, int R, string& s) {
		int quanTemp = 0;
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			quanTemp++;
			L--;
			R++;
		}
		return quanTemp;
	}
};