class Solution {
public:
    int ROWS;
    int COLS;
    vector<vector <int>> visited;
    vector<string> resString;
    bool foundFlag = false;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();

        
        for(string word : words){
            visited = vector<vector<int>>(ROWS, vector<int>(COLS,0));
            foundFlag=false;
            for (int r =0; r< ROWS && !foundFlag; r++){
                for (int c =0; c< COLS && !foundFlag; c++){
                    if (board[r][c] == word[0]){
                        dfs(board, r,c,word,0);
                    }
                }
            }
        }
        return resString;
    }

    void dfs(vector<vector<char>>& board, int row, int col, string& words, int index){
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS || foundFlag || visited[row][col]|| (board[row][col] != words[index])){
            return;
        }
        char boardChar = board[row][col];
        char stringChar = words[index];


        if(index == words.length()-1 && boardChar == stringChar){
            resString.push_back(words);
            foundFlag = true;
            return;
        }

        visited[row][col] =1;
        dfs(board, row+1, col, words, index+1);
        dfs(board, row, col+1, words, index+1);
        dfs(board, row-1, col, words, index+1);
        dfs(board, row, col-1, words, index+1);
        visited[row][col] =0;
    }
};
