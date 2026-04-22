class NumArray {
public:
vector<int> prefix_sum;
    NumArray(vector<int>& nums) {
        int curSum =0;
        for(int val : nums){
            curSum += val;
            prefix_sum.push_back(curSum);
        }
    }
    
    int sumRange(int left, int right) {
        int prefixRight = prefix_sum[right];
        int prefixLeft = (left ==0)? 0 : prefix_sum[left-1];
        return prefixRight - prefixLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */