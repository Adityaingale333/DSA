class Solution {
public:
   /* bool solve(int i, string& s, int j, string& p, vector<vector<int>>& t){
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
    }*/
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        t[0][0] = 1; // both string matched and exhausted

        for(int i=1; i<m+1; i++){
            t[i][0] = 0; // p exhausted but not string
        }

        for(int j=1; j<n+1; j++){
            if(p[j-1] == '*'){
                t[0][j] = 1;
            }
            else{
                for(int k=j; k<n+1; k++){
                    t[0][k] = 0;
                }
                break;
            }
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    t[i][j] = t[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    t[i][j] = t[i-1][j] || t[i][j-1];
                }
                else{
                    t[i][j] = 0;
                }
            }
        }

        return t[m][n] ;
    }
};