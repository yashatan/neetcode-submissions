class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hashSet;
        int L = 0;
        for(int R =0; R < nums.size(); R++){
            if((R-L)>k){
                hashSet.erase(nums[L]);
                L++;
            }

            if(hashSet.count(nums[R])){
                return true;
            }

            hashSet.insert(nums[R]);
        }

        return false;
    }
};