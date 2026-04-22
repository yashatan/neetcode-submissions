class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int curSum =0;
        int L =0;
        int res =0;

        for(int R=0; R< arr.size(); R++){
            if ((R-L+1)>k){
                curSum -= arr[L];
                L++;
            }
            curSum += arr[R];

            if ((R-L == k-1)   && (curSum/k >= threshold)) res++;
        }
        return res;
    }
};