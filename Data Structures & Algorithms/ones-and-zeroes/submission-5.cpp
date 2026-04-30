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

        // for (int i = 0; i < memo.size(); ++i) {
        //     //cout << "Tang " << i << ":" << endl;

        //     // Duyệt qua từng hàng (vector<int>)
        //     for (int j = 0; j < memo[i].size(); ++j) {
        //         //cout << "  Hang " << j << ": ";

        //         // Duyệt qua từng phần tử (int)
        //         for (int k = 0; k < memo[i][j].size(); ++k) {
        //             if (memo[i][j][k] >-1)
        //             cout << "[" << i << "]" << "[" << j << ", " << k << "] = " << memo[i][j][k] << " " << endl;
        //         }
        //     }
        // }
        cout << res;
        //cout << "[" << 0<<"]" << "[ " << 0 << ", " << 0 <<"] " << "= " << memo[0][{0, 0}]  << endl;
        return res;
    }

    int dfs(int index, vector<string>& strs, int cur0, int cur1, int m, int n, bool lr) {
        // cout << (lr==true?"take":"skip") << endl;
        // cout << "index: " << index << " -- " << strs[index] << endl;

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
        // cout << "thisstr0 " << thisstr0 << endl;

        int thisstr1 = zerosAndOne[index].second;
        // cout << "thisstr1 " << thisstr1 << endl;
        if (memo[index][cur0][cur1] == -1) memo[index][cur0][cur1] = 0;
        memo[index][cur0][cur1] += max(dfs(index + 1, strs, cur0, cur1, m, n, false),
            1 + dfs(index + 1, strs, cur0 + thisstr0, cur1 + thisstr1, m, n, true));
        //cout << "[" << index<<"]" << "[ " << cur0 << ", " << cur1 <<"] " << "= " << memo[index][{cur0, cur1}]  << endl;
        return memo[index][cur0][cur1];
    }
};