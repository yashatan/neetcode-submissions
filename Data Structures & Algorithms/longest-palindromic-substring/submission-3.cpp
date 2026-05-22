class Solution {
public:
	string res ="";
	string longestPalindrome(string s) {
		for (int i = 0; i < s.length(); i++) {
			int tempLength = 0;
			string temp = dfs(i, i, s);
			if (res.length() < temp.length()) { 
				res = temp; }
		}

		for (int i = 0; i < s.length()-1; i++) {
			int tempLength = 0;
			string temp = dfs(i, i+1, s);
			if (res.length() < temp.length()) { 
				res = temp; }
		}

		return res;
	}

	string dfs(int L, int R, string& s) {
		string resTemp="";
		while (L >= 0 && R < s.length() && s[L] == s[R]) {
			resTemp = s.substr(L, R-L+1);
			L--;
			R++;
		}
		return resTemp;
	}
};