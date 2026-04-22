class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int lengthRes =0;
        int curLength =0;
        int L =0;

        for (int R =0; R< s.length(); R++){
            if(charSet.count(s[R])==1){
                while(s[L]!=s[R]){
                    charSet.erase(s[L]);
                    L++;
                }
                L++;
            }
            cout << endl;
            charSet.insert(s[R]);
            lengthRes=max(lengthRes, R-L+1);
        }
        return lengthRes;
    }
};
