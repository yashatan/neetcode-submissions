class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> mapofSstring;
        unordered_map<char, int> mapofTstring;


        for (int i=0; i< s.length();i++){
            mapofSstring[s[i]]++;
            mapofTstring[t[i]]++;
        }

return mapofSstring == mapofTstring;
    }
};
