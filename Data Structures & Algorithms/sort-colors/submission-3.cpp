class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[] ={0,0,0};
        for (int i =0; i<nums.size();i++){
            int n = nums[i];
            counts[n] +=1;
        }
    
        int i =0;
        for (int n =0; n < 3;n++){
            for(int j = 0; j< counts[n];j++){
                nums[i] = n;
             i++;
           }
       }
    }   
};