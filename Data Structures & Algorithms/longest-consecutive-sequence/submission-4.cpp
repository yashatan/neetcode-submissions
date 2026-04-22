// class UnionFind {
// public:
//     unordered_map<int, int> par_;
//     unordered_map<int, int> rank_;

//     UnionFind(int n) {
//         for (int i = 1; i <= n; i++) {
//             par_[i] = i;
//             rank_[i] = 0;
//         }
//     }
//     int find(int x) {
//     // Finds the root of x
//         if (x != par_[x]) {
//             par_[x] = find(par_[x]);
//         }
//         return par_[x];
//     }

//     bool cunion(int n1, int n2) {
//         int p1 = find(n1), p2 = find(n2);
//         if (p1 == p2) {
//             return false;
//         }

//         if (rank_[p1] > rank_[p2]) {
//             par_[p2] = p1;
//         } else if (rank_[p1] < rank_[p2]) {
//             par_[p1] = p2;
//         } else {
//             par_[p1] = p2;
//             rank_[p2] += 1;
//         }
//         return true;
//    }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2){
            return nums.size();
        }
        int L =0;
        int duplicate =0;
        int res=1;
        for(int R =1; R < nums.size(); R++){
            if (nums[R] == nums[R-1]){
                duplicate++;
                continue;
            }
            if(nums[R] > (nums[R-1]+1)){
                duplicate =0;
                L=R;
            }
            res = max(res, R-L+1-duplicate);
        }
        return res;
    }
};
