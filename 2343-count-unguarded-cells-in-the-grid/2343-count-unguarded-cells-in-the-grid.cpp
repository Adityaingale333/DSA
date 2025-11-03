class Solution {
public:
    // unguarded = 0;
    // guarded = 1;
    // guards = 2
    // walls = 3;

    void markGuarded(int row, int col, vector<vector<int>>& grid){
        // up
        for(int i=row-1; i>=0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }

            grid[i][col] = 1;
        }

        // down
        for(int i=row+1; i<grid.size(); i++){
            if(grid[i][col] == 2 || grid[i][col] == 3){
                break;
            }

            grid[i][col] = 1;
        }

        // right
        for(int i=col+1; i<grid[0].size(); i++){
            if(grid[row][i] == 2 || grid[row][i] == 3){
                break;
            }

            grid[row][i] = 1;
        }

        // left
        for(int i=col-1; i>=0; i--){
            if(grid[row][i] == 2 || grid[row][i] == 3){
                break;
            }

            grid[row][i] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(int i=0; i<walls.size(); i++){
            int x = walls[i][0];
            int y = walls[i][1];

            grid[x][y] = 3;
        }

        for(int i=0; i<guards.size(); i++){
            int x = guards[i][0];
            int y = guards[i][1];

            grid[x][y] = 2;
        }

        for(vector<int>& guard : guards){
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid);
        }

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    ans++;
                }
            }
        }

        return ans;
    }
};