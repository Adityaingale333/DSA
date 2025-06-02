class Solution {
public:
    /*int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& t){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int up = grid[i][j] + solve(i-1, j, grid, t);

        int left = grid[i][j] + solve(i, j-1, grid, t);

        return t[i][j] = min(up, left);
    }*/
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0){
                    t[i][j] = grid[i][j];
                }
                else{
                    int up = grid[i][j];
                    if(i>0) up = up + t[i-1][j];
                    else up = up + 1e9;
                    int left = grid[i][j];
                    if(j>0) left = left + t[i][j-1];
                    else left = left + 1e9;
                    t[i][j] = min(up, left);
                }
            }
        }

        return t[m-1][n-1];
    }
};