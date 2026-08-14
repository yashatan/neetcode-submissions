class Solution {
public:
    set<pair<int,int>> pac;
    set<pair<int,int>> alt;
    int rows;
    int cols;
    vector<vector<int>> res;


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        for (int r = 0; r < rows; r++) {
            startHere(heights, r, 0, heights[r][0], pac);
            startHere(heights, r, cols-1, heights[r][cols-1], alt);
        }

        for (int c = 0; c < cols; c++) {
            startHere(heights, 0, c, heights[0][c], pac);
            startHere(heights, rows-1, c, heights[rows-1][c], alt);
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pac.count({ r,c }) && alt.count({ r,c })) {
                    res.push_back({ r,c });
                }
            }
        }
        return res;
    }

    void startHere(vector<vector<int>>& heights, int r, int c, int lastval, set<pair<int, int>>& visit) {
        if (r < 0 || c < 0 || r == rows || c == cols || visit.count({ r,c }) || lastval > heights[r][c]) {
            return;
        }

        visit.insert({ r,c });

        startHere(heights, r + 1, c, heights[r][c], visit);
        startHere(heights, r, c + 1, heights[r][c], visit);
        startHere(heights, r, c - 1, heights[r][c], visit);
        startHere(heights, r - 1, c, heights[r][c], visit);

    }
};