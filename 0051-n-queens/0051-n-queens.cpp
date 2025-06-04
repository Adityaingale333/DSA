class Solution {
public:
    int N;
    bool isPossible(int row, int col, vector<string>& temp){
        for(int i=row-1; i>=0; i--){
            if(temp[i][col] == 'Q') return false;
        }

        for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++){
            if(temp[i][j] == 'Q') return false;
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(temp[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int i, vector<string>& temp, vector<vector<string>>& ans){
        if(i == N){
            ans.push_back(temp);
            return;
        }

        for(int col=0; col<N; col++){
            if(isPossible(i, col, temp)){
                temp[i][col] = 'Q';
                solve(i+1, temp, ans);
                temp[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(0, temp, ans);
        return ans;
    }
};