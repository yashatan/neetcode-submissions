class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> colSet(9);
        vector<unordered_set<int>> rowSet(9);
        vector<vector<unordered_set<int>>> squareSet(3, vector<unordered_set<int>>(3));

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                int val = board[row][col];
                if(val == (int)'.'){
                    continue;
                }
                if (colSet[col].count(val) || rowSet[row].count(val) ||
                    squareSet[row / 3][col / 3].count(val)) {
                    return false;
                }

                colSet[col].insert(val);
                rowSet[row].insert(val);
                squareSet[row / 3][col / 3].insert(val);
            }
        }
        return true;
    }
};
