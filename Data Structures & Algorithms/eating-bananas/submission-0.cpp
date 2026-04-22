class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l<=r){
            int mid = (l+r)/2;
            int time = calculateTime(piles, mid);
            if(time <= h){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }

    int calculateTime(vector<int>& piles, int speed){
       int time = 0;
        for(int p : piles){
            int temp = p%speed;
            if (temp > 0){
                time = time + (p/speed) + 1;
            }else{
                time = time + (p/speed);
            }
        }
        return time;
    }
};
