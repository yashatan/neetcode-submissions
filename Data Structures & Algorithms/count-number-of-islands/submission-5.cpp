class Solution {
public:
    int mCols;
    int mRows;
    vector<vector<int>> visit;
    int island=0;
    int numIslands(vector<vector<char>>& grid) {
        mRows = grid.size();
        mCols = grid[0].size();
        vector<vector<int>> temp(    mRows,    std::vector<int>(mCols,0));
        visit = temp;
        for(int i=0; i< mRows;i++){
            for(int j=0; j < mCols; j++){
                if (grid[i][j] == '1' && !visit[i][j]){
                    island += countIsland(grid, i, j);
                }
            }
        }

        return island;
    }

    int countIsland(vector<vector<char>>& grid, int row, int col){       

        if ((row < 0) || (col < 0) || (row == mRows) || (col == mCols) || visit[row][col]) {
            return 0;
        }

        if(grid[row][col] == '0'){
                                    return false;
                                            }
                                                    visit[row][col] = 1;

        countIsland(grid, row+1, col);
        countIsland(grid, row, col+1);
        countIsland(grid, row, col-1);
        countIsland(grid, row-1, col);
        return 1;
    }

    void printVisit(){
        for(int i=0; i< mRows;i++){
            for(int j=0; j < mCols; j++){
                cout << visit[i][j]<<" ";
            }
            cout << endl;
        }
    }
};
