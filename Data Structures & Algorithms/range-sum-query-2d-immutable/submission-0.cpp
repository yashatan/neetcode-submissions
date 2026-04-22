class NumMatrix {
public:
    int ROWS;
    int COLS;
    vector<vector<int>> prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        ROWS = matrix.size() +1;
        COLS = matrix[0].size() +1;
        prefixMatrix = vector<vector<int>>(ROWS, vector<int>(COLS,0));

        for(int row = 0; row < matrix.size(); row++){
            int curSum = 0;
            for(int col = 0; col < matrix[0].size(); col++){
                curSum += matrix[row][col];
                prefixMatrix[row+1][col+1] = curSum + prefixMatrix[row][col+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int regionPrefix = prefixMatrix[row2+1][col2+1];
        int topLeftCorner = prefixMatrix[row1][col1];
        int res = regionPrefix -  prefixMatrix[row1][col2+1] - prefixMatrix[row2+1][col1] + topLeftCorner;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */