class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& t){
        if(row == grid.size()-1){
            return grid[row][col];
        }

        if(t[row][col] != -1){
            return t[row][col];
        }

        int cost = INT_MAX;
        for(int j=0; j<grid[0].size(); j++){
            int cell = grid[row][col];
            cost = min(cost, cell + moveCost[cell][j] + solve(row+1, j, grid, moveCost, t));
        }

        return t[row][col] = cost;

    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for(int col=0; col<n; col++){
            ans = min(ans, solve(0, col, grid, moveCost, t));
        }

        return ans;
    }
};