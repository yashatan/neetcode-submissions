class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> colSet(9);
        vector<unordered_set<char>> rowSet(9);
        vector<vector<unordered_set<char>>> squareSet(3, vector<unordered_set<char>>(3));

        for (char row = 0; row < 9; row++) {
            for (char col = 0; col < 9; col++) {
                char val = board[row][col];
                if(val == '.'){
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
