class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) t[0][0] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = t[i-1][j];
                    if(j>0) left = t[i][j-1];
                    t[i][j] = up + left;
                }
            }
        }
        return t[m-1][n-1];
    }
};