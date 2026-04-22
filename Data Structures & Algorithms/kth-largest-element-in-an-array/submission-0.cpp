class Solution {
public:
    priority_queue<int> maxHeap;
    int findKthLargest(vector<int>& nums, int k) {
         for(int num:nums){
            maxHeap.push(0-num);

            if(maxHeap.size()>k){
                maxHeap.pop();
            }
         }

        return 0-maxHeap.top();

    }
};
