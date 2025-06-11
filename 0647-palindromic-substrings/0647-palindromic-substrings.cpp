class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        vector<vector<bool>> t(n, vector<bool>(n, false));
        // state = t[i][j] = true ->s[i:j] is a pallindromic substring, inclusive of both i and j

        for(int len=1; len<=n; len++){ // for every length
            for(int i=0; i+len-1<n; i++){ // starting index
                int j = i+len-1; // position of j

                if(i == j){ // means it is 1 length string 
                    t[i][j] = true;
                }

                else if(i+1 == j){ // means it is of 2 length string
                    t[i][j] = (s[i] == s[j]);
                }

                else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]) ;
                }

                if(t[i][j] == true){
                    count++;
                }
            }
        }
        return count;
    }
};