class Solution {
   public:
    vector<vector<bool>> visited;
    int rows;
    int cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O' && visited[0][i] == false) {
                spread(0, i, board);
            }

            if (board[rows - 1][i] == 'O' && visited[rows - 1][i] == false) {
                spread(rows - 1, i, board);
            }
        }
        for (int i = 1; i < rows - 1; i++) {
            if (board[i][0] == 'O' && visited[i][0] == false) {
                spread(i, 0, board);
            }

            if (board[i][cols - 1] == 'O' && visited[i][cols - 1] == false) {
                spread(i, cols - 1, board);
            }
        }
        //    // printvisited();
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (board[i][j] == 'O' && visited[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void spread(int row, int col, vector<vector<char>> board) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] == 'X' ||
            visited[row][col] == true) {
            return;
        }

        visited[row][col] = true;

        spread(row + 1, col, board);
        spread(row, col + 1, board);
        spread(row - 1, col, board);
        spread(row, col - 1, board);

        return;
    }
};
