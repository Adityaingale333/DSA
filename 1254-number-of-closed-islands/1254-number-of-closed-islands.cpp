class Solution {
public:
    bool bfs(int i, int j, int m, int n, vector<vector<bool>>& visit, vector<vector<int>>& grid){
        visit[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        bool isClosed = true;

        vector<int> dRow{-1, 0, 1, 0};
        vector<int> dCol{0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow < 0 || nrow >= m || ncol < 0 || ncol >= n){
                    isClosed = false;
                }
                else if(grid[nrow][ncol] == 0 && !visit[nrow][ncol]){
                    q.push({nrow, ncol});
                    visit[nrow][ncol] = true;
                }
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
                if(grid[i][j] == 0 && !visit[i][j] && bfs(i, j, m, n, visit, grid)){
                    count++;
                }
            }
        }

        return count;
    }
};