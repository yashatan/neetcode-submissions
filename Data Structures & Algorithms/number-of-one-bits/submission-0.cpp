class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count =0;
        while (n >0){
            if ((n & 0x1) == 1){
                count++;
                cout << "count plus" << endl;
            }
            n = n >> 1;
            cout << "n value after shift: " << n <<endl;
        }
        return count;
    }
};
