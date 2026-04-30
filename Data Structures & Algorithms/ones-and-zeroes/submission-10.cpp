class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<pair<int, int>> zerosAndOne;
    int res = 0;
    int findMaxForm(vector<string>& strs, int m, int n) {

        memo = vector<vector<vector<int>>>(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (string str : strs) {
            int numberofzeros = count(str.begin(), str.end(), '0');
            int numberofones = count(str.begin(), str.end(), '1');
            zerosAndOne.push_back({ numberofzeros, numberofones });
        }

        res = dfs(0, strs, m, n, false);
        return res;
    }

    int dfs(int index, vector<string>& strs,int m, int n, bool lr) {
        if (m<0 || n<0) {
            return -1;
        }

        if (memo[index][m][n] != -1) {
            return memo[index][m][n];
        }

        if (index == strs.size()) {
            return 0;
        }

        if (memo[index][m][n] == -1) memo[index][m][n] = 0;
        memo[index][m][n] += max(dfs(index + 1, strs, m, n, false),
            1 + dfs(index + 1, strs, m - zerosAndOne[index].first, n - zerosAndOne[index].second, true));
        return memo[index][m][n];
    }
};