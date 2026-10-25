class Solution {
public:
    bool dfs(int row, int col, int m, int n, vector<vector<bool>>& visit, vector<vector<int>>& grid){
        if(row < 0 || row >= m || col < 0 || col >= n){
            return false;
        }

        if(grid[row][col] == 1 || visit[row][col]){
            return true;
        }

        visit[row][col] = true;
        bool isClosed = true;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(!dfs(nrow, ncol, m, n, visit, grid)){
                isClosed = false;
            }
        }

        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, visit, grid)){
                    count++;
                }
            }
        }

        return count;
    }
};