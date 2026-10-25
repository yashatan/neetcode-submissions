class Solution {
public:
    bool isHappy(int n) {
        int fast = sumOfAllDigits(n);
        int slow = n;

        while(fast != slow){
            fast = sumOfAllDigits(fast);
            fast = sumOfAllDigits(fast);

            slow = sumOfAllDigits(slow);
        }

        return fast ==1;
    }
    
    int sumOfAllDigits(int n ){
        int res =0;

        while(n > 0){
            res += (n%10)*(n%10);
            n /= 10;
        }

        return res;
    }
};
