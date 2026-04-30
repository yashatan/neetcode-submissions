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

        res = dfs(0, strs, 0, 0, m, n, false);
        return res;
    }

    int dfs(int index, vector<string>& strs, int cur0, int cur1, int m, int n, bool lr) {
        if (cur0 > m || cur1 > n) {
            return -1;
        }

        if (memo[index][cur0][cur1] != -1) {
            return memo[index][cur0][cur1];
        }

        if (index == strs.size()) {
            if (cur0 <= m && cur1 <= n) {
                return 0;
            }
            else {
                return 0;
            }
        }

        int thisstr0 = zerosAndOne[index].first;
        int thisstr1 = zerosAndOne[index].second;
        if (memo[index][cur0][cur1] == -1) memo[index][cur0][cur1] = 0;
        memo[index][cur0][cur1] += max(dfs(index + 1, strs, cur0, cur1, m, n, false),
            1 + dfs(index + 1, strs, cur0 + thisstr0, cur1 + thisstr1, m, n, true));
        return memo[index][cur0][cur1];
    }
};