class Solution {
public:
    // *** Using Blueprint ***

    // recursion nad memoization
    /*int solve(int i, int j, string& s, vector<vector<int>>& t){
        if(i>j){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == s[j]){
            return t[i][j] = solve(i+1, j-1, s, t);
        }

        return t[i][j] = min(1 + solve(i+1, j, s, t), 1 + solve(i, j-1, s, t));
    }*/
    int minInsertions(string s) {
        int n = s.size();

        // t[i][j] -> states that minimum insertion required to make string i to j pallindrome 
        vector<vector<int>> t(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            t[i][i] = 0; // 0 bcz, single characters are always pallindrome, we do not need any insertions
        }

        for(int len=2; len<=n; len++){
            for(int i=0; i + (len-1)<n; i++){
                int j = i + (len-1); // j calculation is simpe, we konw len = j-i+1, then j = i+len-1

                if(s[i] == s[j]){
                    t[i][j] = t[i+1][j-1]; // if bot characters are equal, then we do not need any insertion
                }
                else{ // if characters do not match, then we need to insert that charaacter and star comparing next
                    t[i][j] = min(1 + t[i+1][j], 1 + t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};