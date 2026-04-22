class Solution {
public:
    int mCols;
    int mRows;
    vector<vector<int>> visit;
    int island=0;
    int maxArea =0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
           mRows = grid.size();
        mCols = grid[0].size();
        vector<vector<int>> temp(    mRows,    std::vector<int>(mCols,0));
        visit = temp;
        for(int i=0; i< mRows;i++){
            for(int j=0; j < mCols; j++){
                if (grid[i][j] == 1){
                    int area=0;
                    countIsland(grid, i, j,area);
                    if (area > maxArea){
                        maxArea = area;
                    }
                }
            }
        }

        return maxArea;
    }

    void countIsland(vector<vector<int>>& grid, int row, int col, int& area){       
        if ((row < 0) || (col < 0) || (row == mRows) || (col == mCols) || visit[row][col]) {
            return;
        }

        if(grid[row][col] == 0){
            return;
        }
        visit[row][col] = 1;
        area++;
        countIsland(grid, row+1, col,area);
        countIsland(grid, row, col+1,area);
        countIsland(grid, row, col-1,area);
        countIsland(grid, row-1, col,area);
        // return 1;
    }
};
