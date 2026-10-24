class Solution {
   public:
    int rows;
    int cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                spread(0, i, board);
            }

            if (board[rows - 1][i] == 'O') {
                spread(rows - 1, i, board);
            }
        }
        for (int i = 1; i < rows - 1; i++) {
            if (board[i][0] == 'O') {
                spread(i, 0, board);
            }

            if (board[i][cols - 1] == 'O') {
                spread(i, cols - 1, board);
            }
        }
        //    // printvisited();
        // for (int i = 0; i < rows; i++) {
        //     for (int j = 0; j < cols; j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout <<endl;
        // }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void spread(int row, int col, vector<vector<char>>& board) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] == 'X' ||
            board[row][col] == 'T') {
            return;
        }

        board[row][col] = 'T';

        spread(row + 1, col, board);
        spread(row, col + 1, board);
        spread(row - 1, col, board);
        spread(row, col - 1, board);

        return;
    }
};
