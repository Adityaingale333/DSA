class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;

        // left to right, consider * = (, if open goes negative means close can never be balanced
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '*'){
                open++;
            }
            else {
                open--;
            }
            if(open < 0) return false;
        }
        

        // right to left, consider * = ), if close goes negative means open can never be balanced
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == ')' || s[i] == '*'){
                close++;
            }
            else {
                close--;
            }
            if(close < 0) return false;        
        }
        

        return true;
    }
};