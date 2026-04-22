class KthLargest {
public:
    int kthLargest = 0;
    vector<int> mnums;
    int o=0;
    KthLargest(int k, vector<int>& nums) {
        kthLargest = k;
        mergedSort(nums,0,nums.size()-1);

        // mnums.push_back(0);
        for(int i =0; i< nums.size();i++){
            mnums.push_back(nums[i]);
        }
        // cout << "Start" << endl;
        // for(int k =0; k< mnums.size();k++){
        //     cout << mnums[k] <<endl;
        // }
    }
    
    int add(int val) {
        mnums.push_back(val);
mergedSort(mnums,0,mnums.size()-1);

        return mnums[mnums.size()-kthLargest];
    }


    void mergedSort(vector<int>& nums, int s, int e){
    if (e - s + 1 <= 1) {
        return ;
    }

        int mid = (s+e)/2;

        mergedSort(nums, s, mid);
        mergedSort(nums, mid+1, e);
        merged(nums, s, mid,e);
    }

    void merged(vector<int>&  nums, int s, int mid,int e){
        vector<int> lNums ={nums.begin()+s, nums.begin()+mid+1};
        vector<int> rNums ={nums.begin()+mid+1, nums.begin()+e+1};

        int j=s;
        int lIndex=0;
        int rIndex=0;

        while((lIndex < lNums.size()) && (rIndex < rNums.size())){
            if(lNums[lIndex]<=rNums[rIndex]){
                nums[j] = lNums[lIndex++];
            }else{
                nums[j] = rNums[rIndex++];
            }
            j++;
        }

        while(lIndex<lNums.size()){
           nums[j++] = lNums[lIndex++];
        }

        while(rIndex<rNums.size()){
           nums[j++] = rNums[rIndex++];
        }
    }
};
