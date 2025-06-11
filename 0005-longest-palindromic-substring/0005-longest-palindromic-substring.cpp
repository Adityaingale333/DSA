class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        int startIdx = -1;
        int maxLen = 0;

        vector<vector<bool>> t(n, vector<bool>(n, false));

        for(int len=1; len<=n; len++){
            for(int i=0; i + len-1<n; i++){
                int j = i + len-1; 

                if(i == j){
                    t[i][j] = true;
                }
                else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                }
                else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j] && j-i+1 > maxLen){
                    startIdx = i;
                    maxLen = j-i+1;
                }

            }
        }
        return s.substr(startIdx, maxLen);
    }
};