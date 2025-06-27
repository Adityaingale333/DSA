class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int rotten = 0;
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(t, time);

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2 ){
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                    rotten++;
                }
            }
        }

        /*for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }*/

        if(fresh != rotten) return -1;

        return time;
    }
};