class Solution {
public:
    /*int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t){
        if(j<0 || j>=matrix.size()){
            return 1e9;
        }
        if(i == 0){
            return matrix[i][j];
        }
        
        if(t[i][j] != -1){
            return t[i][j];
        }

        int up = matrix[i][j] + solve(i-1, j, matrix, t);

        int diaLeft = matrix[i][j] + solve(i-1, j-1, matrix, t);

        int diaRight = matrix[i][j] + solve(i-1, j+1, matrix, t);

        return t[i][j] = min(up, min(diaLeft, diaRight));
    }*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> t(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            t[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + t[i-1][j];
                int ld = matrix[i][j];
                if(j-1>=0) ld = ld + t[i-1][j-1];
                else ld = ld + 1e9;
                int rd = matrix[i][j];
                if(j+1 < n) rd = rd + t[i-1][j+1];
                else rd = rd + 1e9;
                t[i][j] = min(up, min(ld, rd));
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, t[n-1][j]);
        }

        return ans;
    }
};