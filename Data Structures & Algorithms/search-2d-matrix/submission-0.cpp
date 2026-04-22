class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int L =0;
        int R = m*n-1;

                int mid;
        while (L<=R){
            mid = (L+R)/2;
            int row;
            int col;
            calculateIndex(mid, n, &row, &col);
            if (target < matrix[row][col]){
                R=mid-1;
            }else if (target > matrix[row][col]){
                L =mid+1;
            }
            else{
                return true;
            }
        }

        return false;
    }

    void calculateIndex(int mid, int n, int* row, int* column){
        *row = mid/n;
        *column = mid - (*row)*n;
    }
};
