class Solution {
public:
    bool isValid(string s) {
        bool result = false;
        if (s.length()%2==1){
            return false;
        }else{
            stack<char> openingbrackets;
            stack<char> endingbrackets;
            for (int i = 0; i < s.length();i++){
                if(isOpenningBracket(s[i])){
                    openingbrackets.push(s[i]);
                }else{
                    if(openingbrackets.empty()){
                        return false;
                    }
                    if (!isBracketValid(openingbrackets.top(),s[i])){
                        return false;
                    }else{
                        openingbrackets.pop();
                    }
                }
            }
            if (openingbrackets.size() >0){
                return false;
            }
        }
        return true;
    }

    bool isBracketValid(char begin, char end){
            if ((begin == '(' && end==')') || (begin == '{' && end=='}') || (begin == '[' && end==']') ){
                return true;
            }
            return false;
    }
    bool isOpenningBracket(char bracket){
        if((bracket == '(') || (bracket == '[') ||(bracket == '{') ){
            return true;
        }else{
            return false;
        }
    }
};
