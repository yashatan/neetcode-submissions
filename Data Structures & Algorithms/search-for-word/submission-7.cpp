class Solution {
   public:
    int row, col = 0;
        set<pair<int, int>> path;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                    if (backtrack(board, word, 0, r, c)) {
                        return true;
                    }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int k,                   int r, int c) {
        if (k == word.length()) {
            return true;
        }

        if (r < 0 || r >= row) {
            return false;
        }

        if (c < 0 || c >= col) {
            return false;
        }

        if ( path.count({r, c})) {
            return false;
        }
        char curChar = board[r][c];

        if (curChar != word[k]) {
            return false;
        }

        path.insert({r, c});
        bool res =  (backtrack(board, word, k + 1, r - 1, c) ||
                backtrack(board, word, k + 1, r, c - 1) ||
                backtrack(board, word, k + 1, r + 1, c) || backtrack(board, word, k + 1, r, c + 1));
        path.erase({r, c});
        return res;

    }
};
