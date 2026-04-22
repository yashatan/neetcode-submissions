class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPtr = nums[0];
        int fastPtr = nums[0];

        slowPtr = nums[slowPtr];
        fastPtr = nums[nums[fastPtr]];
            
        while(slowPtr != fastPtr){
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        }

        fastPtr = nums[0];

        while(slowPtr != fastPtr){
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }

        return slowPtr;
    }
};
