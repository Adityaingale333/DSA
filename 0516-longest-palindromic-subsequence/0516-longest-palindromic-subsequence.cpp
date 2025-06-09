class Solution {
public:
    int solve(int i, int j, string& s, string& s2, vector<vector<int>>& t){
        if(i == s.size() || j == s2.size()){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == s2[j]){
            return t[i][j] = 1 + solve(i+1, j+1, s, s2, t);
        }
        else{
            return t[i][j] = max(solve(i+1, j, s, s2, t), solve(i, j+1, s, s2, t));
        }

    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> t(n, vector<int>(n, -1));
        return solve(0, 0, s, s2, t);
    }
};