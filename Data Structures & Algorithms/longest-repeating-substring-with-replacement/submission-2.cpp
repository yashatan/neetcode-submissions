class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charMap;
        int L =0;
        int res =0;
        int maxf =0;

        for (int R =0; R < s.length(); R++){
            charMap[s[R]]++;
            maxf = max(maxf, charMap[s[R]]);
            while(R - L +1 - maxf > k){
                charMap[s[L]]--;
                L++;
            }

            res = R-L+1;
        }
        return res;
    }
};
