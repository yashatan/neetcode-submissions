class Solution {
public:
    vector<vector<int>> cache;
    int uniquePaths(int m, int n) {
        cache = vector<vector<int>>(m, vector<int>(n,0));
        return countPath(0,0,m,n);
    }

    int countPath(int r, int c, int rows, int cols){
        if(r == rows || c == cols){
            return 0;
        }
        if (cache[r][c] != 0){
            return cache[r][c];
        }
        if (r == rows-1 || c == cols -1){
            return 1;
        }

        cache[r][c] = countPath(r+1, c, rows, cols) + countPath(r,c+1,rows,cols);
        return cache[r][c];
    }
};
