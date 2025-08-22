class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mini = m, maxi = 0;
        int minj = n, maxj = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    mini = min(mini, i);
                    maxi = max(maxi, i);

                    minj = min(minj, j);
                    maxj = max(maxj, j);
                }
            }
        }

        return (maxi - mini + 1) * (maxj - minj + 1);
    }
};