class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int count = 0;
        string result;
        for(char c : s){
            if(c == '('){ // inc counter if '(' , if its first ( do not include 
                count++;
                if(count != 1) result.push_back('(');
            }
            else{       // dec counter if ')' , if count goes 0 do not include
                count--;
                if(count > 0) result.push_back(')'); 
            }
        }
        return result;
    }
};