class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size(), 0);

        //prefixProduct[0] = nums[0];
        int zeroIndex = -1;
        int totalProduct = 1;
        for(int i =0; i < nums.size(); i ++){
            totalProduct *= nums[i];
            if (totalProduct == 0){
                zeroIndex = i;
                break;
            }
        }

        if (zeroIndex >=0){
            int curProduct =1;
            cout << "zero" << zeroIndex << endl;
            for(int i =0; i < nums.size(); i ++){
                if (zeroIndex != i){
                    cout << "i " << nums[i] << endl;
                    curProduct *= nums[i];
                }
                prefixProduct[zeroIndex] = curProduct;
            }
            return prefixProduct;
        }


        for(int i =0; i < nums.size(); i ++){
            prefixProduct[i] = totalProduct/nums[i];
        }
        return prefixProduct;
    }
};
