class Solution {
public:
    int rows;
    int cols;
    vector<vector<long long>> cache;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        cache = vector<vector<long long>>(rows, vector<long long>(cols,0));
        return countPath(0,0,rows,cols,obstacleGrid);
    }

        long long countPath(int r, int c, int rows, int cols, vector<vector<int>>& grid){
        if(r == rows || c == cols || grid[r][c]==1 ){
            return 0;
        }
        if (cache[r][c] != 0){
            return cache[r][c];
        }
        if (r == rows-1 && c == cols -1){
            // cout << "valid: " << r << " "<< c << endl;
            return 1;

        }

        cache[r][c] = countPath(r+1, c, rows, cols,grid) + countPath(r,c+1,rows,cols,grid);
        // cout << "cache" << endl;
        // for(auto row : cache){
        //     for (auto value : row){
        //         cout << value << " ";

        //     }
        // cout << endl;
        // }
        return cache[r][c];
    }
};