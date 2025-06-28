class Solution {
public:
    // we can also do it using bfs, but most intutive way is dfs
    // this is just for ptactice 
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // first row, first col, last row, last col
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

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