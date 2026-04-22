class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        for (int i =0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        cout << "check 1" <<endl;
        for (int i =0; i < stones.size(); i++){
            int stone_1 = pq.top();
            pq.pop();
            int stone_2 = pq.top();
            pq.pop();
            int a = stone_1 -stone_2;
            if (a!=0){
                pq.push(a);
            }else{
                i++;
            }
        }
                cout << "check 2" <<endl;

        if (pq.size() >0){
            return pq.top();
        }
        return 0;

    }

    // int smash(int& stones_1,int& stones_2, vector<int>& stones){
    //     if (numberofStones==1){
    //         return stones[0];
    //     }
    //     if (numberofStones==0){
    //         return 0;
    //     }
    //     if(stones_1 != stones_2){
    //         stones[numberofStones-2] = abs(stones_1-stones_2);
    //         numberofStones--;
    //     }else{
    //         numberofStones -=2;
    //     }
    //     sort(stones.begin(), stones.begin()+numberofStones);
    //     return smash(stones[numberofStones-1], stones[numberofStones-2], stones);
    // }
    
};
