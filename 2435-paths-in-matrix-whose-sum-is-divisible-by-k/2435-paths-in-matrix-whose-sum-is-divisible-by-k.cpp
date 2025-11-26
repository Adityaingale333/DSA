class Solution {
public:
    int M = 1e9 + 7;
    // int solve(int i, int j, vector<vector<int>>& grid, int rem, int k, vector<vector<vector<int>>>& t){
    //     if(i == grid.size()-1 && j == grid[0].size()-1){
    //         if((rem + grid[i][j]) % k == 0){
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     if(i >= grid.size() || j >= grid[0].size()){
    //         return 0;
    //     }

    //     if(t[i][j][rem] != -1){
    //         return t[i][j][rem];
    //     }

    //     long long right = solve(i, j+1, grid, (rem + grid[i][j]) % k, k, t);
    //     long long down = solve(i+1, j, grid, (rem + grid[i][j]) % k, k, t);

    //     return t[i][j][rem] = (right + down) % M;
    // }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(k, 0)));

        t[m-1][n-1][grid[m-1][n-1] % k] = 1;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;

                for(int rem=0; rem<k; rem++){
                    int nextRem = (rem - grid[i][j] % k + k) % k;
                    long long right = 0;
                    if(j+1 < n){
                        right = t[i][j+1][nextRem];
                    }
                    long long down = 0;
                    if(i+1 < m){
                        down = t[i+1][j][nextRem];

                    }   
                    t[i][j][rem] = (right + down) % M;
                }
            }
        }

        return t[0][0][0];
    }
};