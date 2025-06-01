class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& t){
        if(i == 0 && j == 0){
            return obstacleGrid[0][0] == 1 ? 0 : 1;
        }
        if( i < 0 || j < 0 || obstacleGrid[i][j] == 1){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int up = solve(i-1, j, obstacleGrid, t);

        int left = solve(i, j-1, obstacleGrid, t);

        return t[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve(m-1, n-1, obstacleGrid, t);
    }
};