class Solution {
public:
    unordered_set<int> seta;
    int singleNumber(vector<int>& nums) {
        for (auto num: nums){
            if(seta.count(num)){
                seta.erase(num);
            }else{
                seta.insert(num);
            }
        }
        int res = *seta.begin();
        return res;
    }
};
