class Solution {
public:
    void solve(int l, int r, string& s, int& startIdx, int& maxLen){
        while(l>=0 && r<s.length() && s[l] == s[r]){
            l--;
            r++;
        }

        if( (r-1) - (l+1) + 1 > maxLen){
            startIdx = l+1;
            maxLen = (r-1) - (l+1) + 1;
        }
    }
    string longestPalindrome(string s){
        int n = s.size();
        int startIdx = -1;
        int maxLen = 0;

        for(int i=0; i<n; i++){
            solve(i, i, s, startIdx, maxLen);

            solve(i, i+1, s, startIdx, maxLen);
        }
        return s.substr(startIdx, maxLen);
    }
};