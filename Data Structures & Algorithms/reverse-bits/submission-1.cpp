class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        uint8_t i=31;
        while (n>0){
            cout << "n: " << n << endl; 
            res |= ((n&0x1)<<i);
            cout << "res: " << res << endl; 
            n = n >> 1;
            i--;
        }
        return res;
    }
};
