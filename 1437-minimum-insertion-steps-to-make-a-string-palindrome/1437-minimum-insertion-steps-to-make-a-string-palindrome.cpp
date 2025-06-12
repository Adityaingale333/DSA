class Solution {
public:
// recursion nad memoization
    int solve(int i, int j, string& s, vector<vector<int>>& t){
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
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> t(n, vector<int>(n, -1));
        return solve(0, n-1, s, t);
    }
};