class Solution {
public:
    int numberofStones=0;
    int lastStoneWeight(vector<int>& stones) {
        numberofStones = stones.size();
        sort(stones.begin(), stones.end());


        return smash(stones[numberofStones-1], stones[numberofStones-2], stones);

    }

    int smash(int& stones_1,int& stones_2, vector<int>& stones){
        if (numberofStones==1){
            return stones[0];
        }
        if (numberofStones==0){
            return 0;
        }
        if(stones_1 != stones_2){
            stones[numberofStones-2] = abs(stones_1-stones_2);
            numberofStones--;
        }else{
            numberofStones -=2;
        }
        sort(stones.begin(), stones.begin()+numberofStones);
        return smash(stones[numberofStones-1], stones[numberofStones-2], stones);
    }
    
};
