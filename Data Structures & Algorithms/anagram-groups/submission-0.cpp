class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<unordered_map<char, int>> mapVector;
        unordered_set<string> stringSet;
        vector<vector<string>> res;
        for (auto str : strs) {
            unordered_map<char, int> tempMap;
            for (char s : str) {
                tempMap[s]++;
            }
            mapVector.push_back(tempMap);
        }

        for (int i = 0; i < mapVector.size(); i++) {
            if (stringSet.count(strs[i]) == 0) {
                vector<string> temp;
                stringSet.insert(strs[i]);
                temp.push_back(strs[i]);
                for (int j = i + 1; j < mapVector.size(); j++) {
                    if (mapVector[j] == mapVector[i]) {
                        temp.push_back(strs[j]);
                        stringSet.insert(strs[j]);
                    }
                }
                res.push_back(temp);
            }
        }

        return res;
    }
};