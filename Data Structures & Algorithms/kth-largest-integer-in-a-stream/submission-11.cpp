class KthLargest {
public:
    int kthLargest = 0;
    vector<int> mnums;
    int o=0;
    KthLargest(int k, vector<int>& nums) {
        kthLargest = k;
        for(int i =0; i< nums.size();i++){
            mnums.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        mnums.push_back(val);
        sort(mnums.begin(), mnums.end());

        return mnums[mnums.size()-kthLargest];
    }


};
