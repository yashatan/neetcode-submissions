class Solution {
public:
    bool isPalindrome(string s) {
        int L =0;
        int R = s.length() -1;
        
        while(L < R){
            if (!checkChar(s[L])){
                L++;
                continue;
            }

            if (!checkChar(s[R])){
                R--;
                continue;
            }

            if( !checkSame(s[L], s[R])){
                return false;
            }

            R--;
            L++;
        }

        return true;
    }

    bool checkChar(char c){
        if(( 'A' <= c && c <= 'Z') || ( '0' <= c && c <= '9') || ( 'a' <= c && c <= 'z') ){
             
            
            return true;
        }
        cout << "test 2" << c <<endl;
        return false;
    }

    bool checkSame(char c1, char c2){
        if (c1 == c2){
            return true;
        }

        if (  ((( 'A' <= c1 && c1 <= 'Z') || ( 'a' <= c1 && c1 <= 'z'))&&( 'A' <= c2 && c2 <= 'Z') || ( 'a' <= c2 && c2 <= 'z'))&&(c1+32 == c2)|| (c2+32 ==c1)){
            return true;
        }
         cout << "not same" << c1 << " " << c2 << endl;
        return false;
    }
};
