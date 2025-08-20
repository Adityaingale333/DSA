class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& t){
        if(i>=matrix.size() || j>=matrix[0].size() ||matrix[i][j] == 0){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int right = solve(i, j+1, matrix, t);
        int dia = solve(i+1, j+1, matrix, t);
        int down = solve(i+1, j, matrix, t);

        return t[i][j] = 1 + min({right, dia, down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    ans = ans + solve(i, j, matrix, t);
                }
            }
        }

        return ans;
    }
};