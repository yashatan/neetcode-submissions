class Solution {
public:
    vector<int> res;
    unordered_set<int> oset;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0; i< nums.size(); i ++){
            if(oset.count(target-nums[i])){
                for(int j =0;j<i; j++){
                    if (nums[j] == target-nums[i]){
  res.push_back(j);
                    }
                                  
                }
                res.push_back(i);
            }
            oset.insert(nums[i]);
        }
        return res;
    }
};
