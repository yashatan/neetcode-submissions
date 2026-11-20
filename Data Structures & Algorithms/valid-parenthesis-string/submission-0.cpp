class Solution {
   public:
    bool checkValidString(string s) {
        // duyệt từ trái qua phải xem tính leftMin và leftMax
        //  nếu leftMin == 0 thì true
        //  nếu leftMax < 0 ngay lập tức return false

        int leftMin = 0;
        int leftMax = 0;

        for (auto c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0) {
                return false;
            }

            leftMin = max(0, leftMin);
        }

        return leftMin == 0;
    }
};
