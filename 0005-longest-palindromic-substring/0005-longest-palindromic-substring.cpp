class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        // will use these two variable for generating s.substr()
        int startIdx = -1; // variable for storing starting index
        int maxLen = 0; // variable for storing maxlen

        // 2D dp table for storing whether the substring from i to j, is pallindrome or not
        vector<vector<bool>> t(n, vector<bool>(n, false)); 

        for(int len=1; len<=n; len++){ // we want substring of all possible lengths
            for(int i=0; (i + len-1)<n; i++){ // these are the starting indexes of the substring off all lengths

            // this is end index of the substring, we calculate it by the logic of length required, 
            // we want len 4, so if i = 0, then j = 0 + (len-1), = 3
                int j = i + len-1; 

                if(i == j){ // this is the case of substring of length 1, always pallindrome
                    t[i][j] = true;
                }
                else if(i+1 == j){ // this is the case of substring of length 2, will be pallindrome if both s[i] and s[j] are same
                    t[i][j] = (s[i] == s[j]);
                }
                // this is the general case, length > 2
                // here we need tho check if the first and last character are same, and then we check if the
                // remaining substring from i+1 to j-1, is palliindrome or not
                else{ 
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j] && j-i+1 > maxLen){ // if t[i][j] is pallindrome and we got new maxLen
                    startIdx = i;              // then we update starting index 
                    maxLen = j-i+1;            // and maxLen
                }

            }
        }
        return s.substr(startIdx, maxLen);
    }
};