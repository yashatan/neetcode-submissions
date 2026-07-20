class Solution {
public:
    int maxArea(vector<int>& heights) {
        int curMax =0;
        int L =0;
        int R = heights.size() -1;
        while(L<R){
            int area = min(heights[L], heights[R])*(R-L);
            curMax = max(area, curMax);

            if(heights[L] < heights[R]){
                L++;
            }else{
                R--;
            }
        }
        return curMax;
    }
};
