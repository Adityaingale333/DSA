class Solution {
public:
    bool valid(char &ch){
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }

    char toLower(char &ch){
        if(ch>='a' && ch<='z'){
            return ch;
        }

        else return  ch - 'A' + 'a';
        
    }

    bool pallindrome(string &s){
        int n = s.length();
        int low = 0, high = n-1;

        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            else{
                low++, high--;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        int n = s.length();

        string temp = "";

        for(int i=0; i<n; i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }

        for(int i=0; i<temp.length(); i++){
            temp[i] = toLower(temp[i]);
        }

        return pallindrome(temp);
    }
};