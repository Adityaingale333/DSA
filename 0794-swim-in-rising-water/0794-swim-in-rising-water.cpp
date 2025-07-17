class Solution {
public:
    // we have to find the shortest path to (n-1, n-1) from (0, 0) 
    // we can do it in many ways
    // on of them being Dijkdtra's Algorithm, with elevation constraint
    int swimInWater(vector<vector<int>>& grid) { 
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n, 0));

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > minh;

        minh.push({grid[0][0], {0, 0}}); // { elevation, {row, col} };

        while(!minh.empty()){
            int elevation = minh.top().first;
            int row = minh.top().second.first;
            int col = minh.top().second.second;
            minh.pop();

            if(row == n-1 && col == n-1){
                return elevation;
            }

            if(visited[row][col] == 1){
                continue;
            }

            visited[row][col] = 1;

            int drow[] = {1, 0, -1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == 0){
                    minh.push({max(elevation, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        } 

        return -1;
    }
};