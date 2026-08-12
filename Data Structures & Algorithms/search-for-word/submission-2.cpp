class Solution {
   public:
    int row, col = 0;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (board[r][c] == word[0]) {
                    vector<vector<bool>> visit(row, std::vector<bool>(col, 0));
                    cout << "found first char " << endl;
                    if (backtrack(board, word, visit, 0, r, c)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>> visit, int k,                   int r, int c) {
        if (k == word.length()) {
            return true;
        }

        if (r < 0 || r >= row) {
            return false;
        }

        if (c < 0 || c >= col) {
            return false;
        }

        if (visit[r][c]) {
            return false;
        }
        char curChar = board[r][c];

        if (curChar != word[k]) {
            return false;
        }

        visit[r][c] = 1;

        cout << "valid char: " << curChar << endl;
        cout << "r: " << r << " c: " << c << endl;
        return (backtrack(board, word,visit, k + 1, r - 1, c) ||
                backtrack(board, word,visit, k + 1, r, c - 1) ||
                backtrack(board, word,visit, k + 1, r + 1, c) || backtrack(board, word,visit, k + 1, r, c + 1));
    }
};
