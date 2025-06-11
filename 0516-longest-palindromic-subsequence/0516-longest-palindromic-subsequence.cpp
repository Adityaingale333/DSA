class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // t[i][j] -> states, longest pallindrome subsequence from index i to j 
        vector<vector<int>> t(n, vector<int>(n, 0));

        // if length 1, then it will always be a pallindrome, it will help in filling dp table
        for(int i=0; i<n; i++){
            t[i][i] = 1;
        }

        for(int len=2; len<=n; len++){
            for(int i=0; (i + len-1)<n; i++){
                int j = i + len-1;

                if(s[i] == s[j]){
                    t[i][j] = 2 + t[i+1][j-1]; // 2 bcz i and j ch matches, and then we look for between them, t[i+1][j-1]
                }
                else{
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }
        return t[0][n-1]; // longest pallindromic subsequence from i to j
    }
};