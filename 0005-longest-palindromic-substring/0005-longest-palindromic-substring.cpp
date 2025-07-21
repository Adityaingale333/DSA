class Solution {
public:
    // expand from centre, keeping track of longest pallindrome
    void solve(int l, int r, string& s, int& maxLen, int& startIdx){
        while(l>=0 && r<s.length() && s[l] == s[r]){
            l--;
            r++;
        }

        // after coming out of the loop, l and r will be off by one, so take care of that
        if( (r-1) - (l+1) + 1 > maxLen){
            maxLen = (r-1) - (l+1) + 1;
            startIdx = l+1 ;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();

        int maxLen = 0;
        int startIdx = 0;

        for(int i=0; i<n; i++){
            solve(i, i, s, maxLen, startIdx); // considering odd length pallindrome

            solve(i, i+1, s, maxLen, startIdx); // considering even length pallindrome
        }

        return s.substr(startIdx, maxLen);
    }
};