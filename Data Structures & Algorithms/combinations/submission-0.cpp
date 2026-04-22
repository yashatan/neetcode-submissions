class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(1,n,k, comb, res);
        return res;
    }

    void dfs(int i, int n, int k, vector<int>& comb, vector<vector<int>>& res){
        if(comb.size() == k){
            res.push_back(vector<int>(comb));
            return;
        }

        if (i > n){
            return;
        }

        for(int j =i; j <=n; j++){
            comb.push_back(j);
            dfs(j+1, n, k, comb, res);
            comb.pop_back();
        }
    }
};
