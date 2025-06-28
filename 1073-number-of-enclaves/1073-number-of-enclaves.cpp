class Solution {
public:
    // so basically we need to find the number of 1's that are not connected to the 1 present on the boundary
    // bcz the only way we can walk off is using the 1 present on the boundary
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        visited[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, visited, grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // dfs on boundary -> first and last row
        for(int j=0; j<n; j++){
            // first row
            if(visited[0][j] == 0 && grid[0][j] == 1){
                dfs(0, j, visited, grid);
            }

            // last row
            if(visited[m-1][j] == 0 && grid[m-1][j] == 1){
                dfs(m-1, j, visited, grid);
            }
        }

        // dfs on boundary -> first and last col
        for(int i=0; i<m; i++){
            // first col
            if(visited[i][0] == 0 && grid[i][0] == 1){
                dfs(i, 0, visited, grid);
            }

            // last col
            if(visited[i][n-1] == 0 && grid[i][n-1] == 1){
                dfs(i, n-1, visited, grid);
            }
        }

        // we will count the number of remaining 1 in mat
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};