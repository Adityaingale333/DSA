class Solution {
public:
    int M = 1e9 + 7;
    int solve(int i, int n, int x, vector<vector<int>>& t){
        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 0;
        }

        int currPower = pow(i, x);
        if(currPower > n) return 0;

        if(t[i][n] != -1){
            return t[i][n];
        }

        int take = solve(i+1, n - currPower, x, t);

        int notTake = solve(i+1, n, x, t);

        return t[i][n] = (take + notTake) % M;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        return solve(1, n, x, t);
    }
};