class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();

        while(s.size() > 2){
            string temp;
            for(int i=0; i<s.size()-1; i++){
                int val = ((s[i] - '0') + (s[i+1] - '0')) % 10;
                temp.push_back(val + '0');
            }
            s = temp;
        }

        if(s.size() != 2) return false;

        if(s[0] != s[1]) return false;

        return true;
    }
};