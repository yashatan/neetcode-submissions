class Solution {
public:
        unordered_map<char, string> keyBoard;
    vector<string> letterCombinations(string digits) {
        int stringSize = digits.length();
        string curComb;
        vector<string> res;
        if(stringSize == 0){
            return res;
        }
        initKeyboard(keyBoard);
        dfs(0, stringSize, digits, curComb, res);
        return res;
    }

    void initKeyboard(unordered_map<char, string>& keyBoard){
        keyBoard['2'] = "abc";
        keyBoard['3'] = "def";
        keyBoard['4'] = "ghi";
        keyBoard['5'] = "jkl";
        keyBoard['6'] = "mno";
        keyBoard['7'] = "pqrs";
        keyBoard['8'] = "tuv";
        keyBoard['9'] = "wxyz";
    }

    void dfs(int digitCharIndex, int stringSize, string digits, string& curComb, vector<string>&res){

        if(digitCharIndex == stringSize){
            res.push_back(string(curComb));
            return;
        }
        char digit = digits[digitCharIndex];
        for(int j =0; j < keyBoard[digit].size(); j++){
            curComb.push_back(keyBoard[digit][j]);
            dfs(digitCharIndex+1, stringSize, digits, curComb, res);
            curComb.pop_back();
        }
    }
};
