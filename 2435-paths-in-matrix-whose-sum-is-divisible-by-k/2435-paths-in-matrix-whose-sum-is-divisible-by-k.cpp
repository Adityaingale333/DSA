class Solution {
public:
    int M = 1e9 + 7;
    int solve(int i, int j, vector<vector<int>>& grid, int rem, int k, vector<vector<vector<int>>>& t){
        if(i == grid.size()-1 && j == grid[0].size()-1){
            if((rem + grid[i][j]) % k == 0){
                return 1;
            }
            return 0;
        }
        if(i >= grid.size() || j >= grid[0].size()){
            return 0;
        }

        if(t[i][j][rem] != -1){
            return t[i][j][rem];
        }

        long long right = solve(i, j+1, grid, (rem + grid[i][j]) % k, k, t);
        long long down = solve(i+1, j, grid, (rem + grid[i][j]) % k, k, t);

        return t[i][j][rem] = (right + down) % M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return solve(0, 0, grid, 0, k, t);
    }
};