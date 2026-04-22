class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int currentCapital = w;
        int remainProject = k;
        int res = 0;
        auto cmp = [](pair<int,int> left, pair<int,int> right) {
        return left.first > right.first;  };


        priority_queue<pair<int, int>, vector<pair<int,int>>,  greater<pair<int,int>>> capitalHeap;
        priority_queue<int> profitHeap;

        for(int i=0; i< capital.size(); i++){
            capitalHeap.push({capital[i], i});
        }

        if(currentCapital < capitalHeap.top().first){
            return currentCapital;
        }
        for (int i = 0; i < k; i++) {
            while (capitalHeap.top().first <= currentCapital && !capitalHeap.empty()){
                profitHeap.push(profits[capitalHeap.top().second]);
                capitalHeap.pop();
            }
            
            if(profitHeap.empty()){
                break;
            }

                currentCapital += profitHeap.top();
                profitHeap.pop();

        }



        return currentCapital;
    }
};