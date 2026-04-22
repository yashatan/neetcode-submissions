class Solution {
public:
    int res =0;
    int trap(vector<int>& height) {
        int L =0;
        
        int curMin = height[0];
         
        for(int R =1; R < height.size(); R++){
            if(height[R] >= height[L]){
                fullFill(L+1, R, height, height[L]);
                L =R;
                curMin = height[L];
            }else{
                if(height[R] > curMin){
                    fullFill(L+1, R, height, height[R]);      
                }
                curMin = height[R];
            }
        }
        return res;
    }

    void fullFill(int start, int end, vector<int>& height, int value){
        for(int i = start; i <end; i++){
            if(height[i] < value){
                res+= value - height[i];
                height[i] = value;
            }
        }
    }
};
