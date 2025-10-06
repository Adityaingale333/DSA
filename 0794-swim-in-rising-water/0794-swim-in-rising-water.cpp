class Solution {
public:
    bool possible(int row, int col, int mid, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(row < 0 || row>=grid.size() || col<0 || col>=grid.size() || visited[row][col] == 1 || grid[row][col] > mid){
            return false;
        }

        visited[row][col] = true;

        if(row == grid.size()-1 && col == grid.size()-1){
            return true;
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(possible(nrow, ncol, mid, grid, visited)){
                return true;
            }
        }

        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = (n*n) - 1;

        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;

            vector<vector<bool>> visited(n, vector<bool>(n, false)); 
            if(possible(0, 0, mid, grid, visited)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};