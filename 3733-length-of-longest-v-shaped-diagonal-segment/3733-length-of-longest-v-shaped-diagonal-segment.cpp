class Solution {
public:
vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
int m, n;
int solve(int i, int j, int d, bool canTurn, int val, vector<vector<int>>& grid){
    int i_ = i + directions[d][0];
    int j_ = j + directions[d][1];

    if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val){
        return 0;
    }

    int ans = 0;
    int keepMoving = 1 + solve(i_, j_, d, canTurn, val == 2 ? 0 : 2, grid);
    ans = max(ans, keepMoving);

    if(canTurn == true){
        int turnAndMove = max(keepMoving, 1 + solve(i_, j_, (d+1)%4, false, val == 2 ? 0 : 2, grid));
        ans = max(ans, turnAndMove);
    }

    return ans;
}
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int d=0; d<=3; d++){
                        ans = max(ans, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        return ans;
    }
};