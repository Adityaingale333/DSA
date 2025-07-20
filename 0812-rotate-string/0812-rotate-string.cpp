class Solution {
public:
    string rotateLeft(string s){
        int n = s.length();

        char first = s[0];

        for(int i=0; i<n-1; i++){
            s[i] = s[i+1];
        }

        s[n-1] = first;

        return s;
    }
    bool rotateString(string s, string goal) {
        int n = s.length();

        for(int i=0; i<n; i++){
            s = rotateLeft(s);
            if(s == goal) return true;
        }

        return false;
    }
};