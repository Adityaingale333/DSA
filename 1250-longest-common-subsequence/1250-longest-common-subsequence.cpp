class Solution {
public: 
    int solve(string& text1, int m, string& text2, int n, vector<vector<int>>& t){
        if(m < 0 || n < 0){
            return 0;
        }

        if(t[m][n] != -1){
            return t[m][n];
        }

        if(text1[m] == text2[n]){
            return 1 + solve(text1, m-1, text2, n-1, t);
        }
    
        return t[m][n] = max(solve(text1, m-1, text2, n, t), solve(text1, m, text2, n-1, t));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> t(m, vector<int>(n, -1));

        return solve(text1, m-1, text2, n-1, t);
    }
};