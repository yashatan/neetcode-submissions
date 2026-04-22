class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i =0; i <= n; i++){
            result.push_back(hammingWeight(i));
        }
        return result;
    }

    int hammingWeight(uint32_t n) {
        int count =0;
        while (n >0){
            if ((n & 0x1) == 1){
                count++;
                cout << "count plus" << endl;
            }
            n = n >> 1;
        }
        return count;
    }
};
