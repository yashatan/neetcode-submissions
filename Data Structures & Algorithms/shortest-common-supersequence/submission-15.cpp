class Solution {
public:

	vector<vector<int>> cache;
	string shortestCommonSupersequence(string str1, string str2) {
		cache = vector<vector<int>>(str1.length()+1, vector<int>(str2.length()+1, -1));
		dfs(0, 0, str1, str2);
		string res = buildString(str1, str2);
		return res;
	}

	int dfs(int i, int j, string& str1, string& str2) {


		if (i == str1.length()) {
			return cache[i][j] = str2.length() - j;
		}


		if (j == str2.length()) {
			return cache[i][j] = str1.length() - i;
		}

		if (cache[i][j] != -1) {
			return cache[i][j];
		}

		if (str1[i] == str2[j]) {
			cache[i][j] = 1 + dfs(i + 1, j + 1, str1, str2);
		}
		else {


			cache[i][j] = 1 + min(dfs(i + 1, j, str1, str2), dfs(i, j + 1, str1, str2));
		}


		return cache[i][j];
	}

	string buildString(string str1, string str2) {
		int i =0, j = 0;
		string temp;
		while (i < str1.length()|| j < str2.length()) {

			if (i == str1.length()) {
				temp += str2.substr(j);
				break;
			}

			if (j == str2.length()) {
				temp += str1.substr(i);
				break;
			}

			if (str1[i] == str2[j]) {
				temp += str1[i];
				i++; j++;
			}
			else {
				if (cache[i + 1][j] < cache[i][j+1]) {
					temp += str1[i];
					i++;
				}
				else {
					temp += str2[j];
					j++;
				}
			}
		}
		return temp;
	}
};