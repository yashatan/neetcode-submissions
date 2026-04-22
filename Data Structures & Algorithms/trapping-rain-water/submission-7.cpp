class Solution {
public:


    int trap(vector<int>& height) {
        int res =0;
        int L = 0;
        int R = height.size()-1;
        int LMax = height[L];
        int RMax = height[R];
        while(L< R){
            if (LMax < RMax){
                L++;
                LMax = max(LMax, height[L]);
                res += LMax - height[L];
            }
            else{
                R--;
                RMax = max(RMax, height[R]);
                res += RMax - height[R];
            }
        }
        return res;
    }


};
