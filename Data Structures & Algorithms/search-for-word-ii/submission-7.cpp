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
            for (int r =0; r< ROWS; r++){
                for (int c =0; c< COLS; c++){
                    if (board[r][c] == word[0]){
                        dfs(board, r,c,word,0);
                    }
                    if(foundFlag){
                        break;
                    }
                }
                if(foundFlag){
                    break;
                }
            }
            //dfs(board, 0,0, word,0);
        }
        return resString;
    }

    void dfs(vector<vector<char>>& board, int row, int col, string& words, int index){
        if (row < 0 || col < 0 || row >= ROWS || col >= COLS){
            return;
        }
        if (foundFlag){
            return;
        }
        if(visited[row][col]==1){
            return;
        }
        char boardChar = board[row][col];
        char stringChar = words[index];


        if(index == words.length()-1 && boardChar == stringChar){
            resString.push_back(words);
            foundFlag = true;
            return;
        }


        if (boardChar != stringChar){
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
