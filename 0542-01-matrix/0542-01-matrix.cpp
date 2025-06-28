class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        vector<vector<int>> dist = mat;

        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j] == 0){
                    q.push({{i,j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        

        int drow[] = {-1, 0, 1, 0}; // up -> right -> down -> left
        int dcol[] = {0, 1, 0, -1}; // up -> right -> down -> left
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && visited[nrow][ncol] == 0 && dist[nrow][ncol] == 1){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, distance+1});
                    dist[nrow][ncol] = distance + 1;
                }
            }
        }

        return dist;
    }
};