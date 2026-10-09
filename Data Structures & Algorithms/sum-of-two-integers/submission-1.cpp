class Solution {
   public:
    int getSum(int a, int b) {
        int tempa;
        int tempb;
        while (b != 0) {
            int carry = a & b;
            carry = carry << 1;

            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
