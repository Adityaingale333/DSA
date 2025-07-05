class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        int level = 0;
        queue<pair<int,int>> q; // row, col
        q.push({0,0});

        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        while(!q.empty()){
            int k = q.size();

            for(int i=0; i<k; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if(row == n-1 && col == n-1) return level + 1;

                for(int i=0; i<8; i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == 0){
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            level++;
        }

        return -1;
    }
};