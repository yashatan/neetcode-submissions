class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> setTrip;
        for (auto triplet : triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }

            if (target[0] == triplet[0]) {
                setTrip.insert(0);
            }

            if (target[1] == triplet[1]) {
                setTrip.insert(1);
            }

            if (target[2] == triplet[2]) {
                setTrip.insert(2);
            }

            if (setTrip.size() == 3){
                return true;
            }
        }

        return setTrip.size() ==3;
    }
};
