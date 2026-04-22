class Solution {
public:
    int res =0;
    int curMin;
    int fullFilledValue =0;
    int trap(vector<int>& height) {
        int L =0;
        vector<int> heiMap;
        curMin = height[0];
         
        for(int R =1; R < height.size(); R++){
            if(height[R] >= height[L]){
                cout << "Full Fill Big " << endl;
                fullFill(L+1, R, heiMap, height[L]);
                L =R;
                curMin = height[L];
            }else{
                if(height[R] > curMin){
                    cout << "Full Fill Small " << endl;
                    fullFill(L+1, R, heiMap, height[R]);      
                }
                heiMap.push_back(height[R]);
                curMin = height[R];
                cout << "new curMin " << curMin<< endl;
                cout << "heiMap " << heiMap.size()<< endl;
                cout << endl;
            }
        }
        return res;
    }

    void fullFill(int start, int end, vector<int>& heiMap, int value){
        int i=0;
        int proceeded =0;
        while(i< heiMap.size()){
            if(heiMap[i] <= value){
                res += value - heiMap[i];
                cout << "res plus " <<res << endl;
                proceeded++;
                heiMap.erase(heiMap.begin()+i);
                cout << "heiMap " << heiMap.size()<< endl;
            }else{
                i++;
            }
        }
        
        res += (value-fullFilledValue)*(end -start-proceeded-heiMap.size());
        fullFilledValue = value;
        cout << "i " <<i << endl;
        cout << "start " <<start << endl;
        cout << "end " <<end << endl;
        cout << "res " <<res << endl;
        cout << endl;

    }
};
