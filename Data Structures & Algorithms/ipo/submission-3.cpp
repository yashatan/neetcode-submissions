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
        while(k>0){
            while (capitalHeap.top().first <= currentCapital && k >0 && !capitalHeap.empty()){
                cout << capitalHeap.top().first << " currentCap: " << currentCapital << endl;
                profitHeap.push(profits[capitalHeap.top().second]);
                capitalHeap.pop();
            }
        //     cout<< profitHeap.top() <<endl;


         if(!profitHeap.empty() && k>0){
                int temp = profitHeap.top();
                currentCapital += temp;
                profitHeap.pop();
                k--;
            }
        }



        return currentCapital;
    }
};