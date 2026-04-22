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
                cout << "chu bi trung " << s[R] << endl;
                cout << "chu bat dau tiep theo " << s[L] << endl;
            }
            for(int debug = L; debug<= R; debug++){
                cout << s[debug];     
            }
            cout << endl;
            charSet.insert(s[R]);
            lengthRes=max(lengthRes, R-L+1);
        }
        return lengthRes;
    }
};
