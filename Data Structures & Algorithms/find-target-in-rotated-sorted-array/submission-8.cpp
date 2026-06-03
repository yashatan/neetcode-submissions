class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int L = 0, R = n - 1;
        int mid = -1;
        bool leftsort = false;
        int res = -1;

        while ((L + R) / 2 != mid) {
            if (L >= R - 1) {
                if (nums[L] == target) res = L;
                if (nums[R] == target) res = R;
                break;
            }
            mid = (L + R) / 2;
            if (target == nums[mid]) {
                res = mid;
                break;
            }
            leftsort = nums[L] < nums[mid];
            if (target < nums[mid]) {
                if (leftsort) {
                    if (target > nums[L]) {
                        R = mid - 1;
                        // mid = (L + R) / 2;
                        continue;
                    } else if (target < nums[L]) {
                        L = mid + 1;
                        // mid = (L + R) / 2;
                    } else {
                        res = L;
                        break;
                    }
                } else {
                    R = mid - 1;
                    // mid = (L + R) / 2;
                    continue;
                }
            } else {
                if (leftsort) {
                    L = mid + 1;
                    // mid = (L + R) / 2;
                    continue;
                } else {
                    if (target > nums[R]) {
                        R = mid - 1;
                        // mid = (L + R) / 2;
                        continue;
                    } else if (target < nums[R]) {
                        L = mid + 1;
                        // mid = (L + R) / 2;
                        continue;
                    } else {
                        res = R;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
