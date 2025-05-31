class Solution {
public:
    bool solve(int i, string& s, int j, string& p, vector<vector<int>>& t){
        if(i < 0 && j < 0){
            return true;
        }
        if(j < 0){
            return false;
        }
        if(i < 0){
            for(int k=0; k<=j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == p[j] || p[j] == '?'){
            return t[i][j] = solve(i-1, s, j-1, p, t);
        }

        if(p[j] == '*'){
            return t[i][j] = solve(i-1, s, j, p, t) || solve(i, s, j-1, p, t);
        }   
        return false;            
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> t(m, vector<int>(n, -1));

        return solve(m-1, s, n-1, p, t);
    }
};