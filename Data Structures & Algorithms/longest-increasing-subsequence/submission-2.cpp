class Solution {
   public:
    unordered_map<int, int> mp;
    int lengthOfLIS(vector<int>& nums) {
        mp[0] = -1000;
        mp[1] = nums[0];
        int curMaxlength = 1;
        for (int i = 1; i < nums.size(); i++) {
            int decreaseStep = 1;

            if (nums[i] > mp[curMaxlength]) {
                mp[++curMaxlength] = nums[i];
                continue;
            } else if (nums[i] == mp[curMaxlength]) {
                continue;
            }else{
                int replaceIndex = timIndexLonNhatNhoHonVal(mp, curMaxlength, nums[i]);
                mp[replaceIndex] = nums[i];
            }
        }

        return curMaxlength;
    }

    int timIndexLonNhatNhoHonVal(unordered_map<int, int>& mp, int size  , int val) {
        int left = 0;
        int right = size;
        int ansIndex = -1;  // Biến lưu trữ kết quả index tốt nhất tìm được

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Tránh tràn số so với (left + right) / 2

            if (mp[mid] < val) {
                ansIndex = mid;  // Ghi nhận mid là một đáp án tạm thời
                left = mid + 1;  // Thử tìm sang bên phải xem có số nào lớn hơn nữa không
            } else {
                right = mid - 1;  // Số hiện tại quá lớn hoặc bằng val, thu hẹp sang bên trái
            }
        }
        cout << ansIndex+1 << endl;
        return ansIndex + 1;  // Trả về index tìm được, hoặc -1 nếu không có số nào < val
    }
};
