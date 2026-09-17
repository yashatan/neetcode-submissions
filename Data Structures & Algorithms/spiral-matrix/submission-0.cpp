class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }
        int rowToGo = matrix.size();
        int colToGo = matrix[0].size();

        vector<int> res;

        // upDown:
        bool trueGoUpFalseGoDown = false;

        // leftRight:
        bool trueGoLeftFalseGoRight = false;

        bool trueHorFalseVer = true;
        int row = 0;
        int col = -1;

        while (rowToGo > 0 && colToGo > 0) {
            // Go Horizon

            if (trueHorFalseVer) {
                for (int i = 0; i < colToGo; i++) {
                    if (!trueGoLeftFalseGoRight) {
                        col++;
                    }
                    else {
                        col--;
                    }
                    res.push_back(matrix[row][col]);

                }

                //if (!trueGoLeftFalseGoRight) col--;
                //else col++;
                rowToGo--;
                trueGoLeftFalseGoRight = !trueGoLeftFalseGoRight;
                trueHorFalseVer = !trueHorFalseVer;
            }
            else {
                for (int i = 0; i < rowToGo; i++) {
                    if (!trueGoUpFalseGoDown) {
                        row++;
                    }
                    else {
                        row--;
                    }
                    res.push_back(matrix[row][col]);

                }
                colToGo--;
                trueGoUpFalseGoDown = !trueGoUpFalseGoDown;
                trueHorFalseVer = !trueHorFalseVer;
            }

            // Go Vertical
        }
        return res;
    }
};