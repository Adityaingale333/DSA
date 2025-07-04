class Solution {
public:
    // we can also say we are using simple bfs, with distance thing
    //                              OR
    // while using dojkstra we will not rquire PQ here, bcz we have unit weights, so we will already get the dist
    // in sorted order such as 1 1 1 1......  ,  2 2 2 2....  ,  3 3 3 3........ 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        if(n == 1) return grid[0][0] == 0 ? 1 : -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;

        queue<pair<int, pair<int,int>>> q; // (distance, {row, col});
        q.push({1, {0,0}}); // dist, {row, col}

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second; 
            q.pop();

            for(int i=0; i<8; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 0 && (d + 1 < dist[nrow][ncol]) ){
                    dist[nrow][ncol] = d + 1;

                    if(nrow == n-1 && ncol == n-1) return d + 1;

                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }

        return -1;
    }
};