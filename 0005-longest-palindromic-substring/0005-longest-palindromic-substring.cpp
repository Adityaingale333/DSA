class Solution {
public:
    int t[1001][1001];

    bool isPallindrome(string& s, int low, int high){
        if(low >= high) return 1;

        if(t[low][high] != -1){
            return t[low][high];
        }
        if(s[low] == s[high]){
            low++, high--;
            return t[low][high] = isPallindrome(s, low, high);
        }
        return t[low][high] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        if(n == 1) return s;

        memset(t, -1, sizeof(t));

        int maxLen= 1;
        int sp = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if( isPallindrome(s, i, j) && j-i+1 > maxLen ){
                    sp = i;
                    maxLen = j-i+1;
                }   
            }
        }
        return s.substr(sp, maxLen); // parameters == (starting point, length)
        
    }
};