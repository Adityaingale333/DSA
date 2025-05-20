class Solution {
public:
    int N;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;
    
    void solve(vector<string>& board, int row, vector<vector<string>>& ans){
        if(row == N){
            ans.push_back(board);
            return;
        }

        for(int col=0; col<N; col++){
            int constDiag = row+col;
            int constAntiDiag = row-col;

            if(cols.find(col) != cols.end() || 
               diag.find(constDiag) != diag.end() ||
               antiDiag.find(constAntiDiag) != antiDiag.end()){
                continue;
            }
            // place Q
            board[row][col] = 'Q';
            // places where we can not put Q in future after putting a Q in above position
            cols.insert(col);
            diag.insert(constDiag);
            antiDiag.insert(constAntiDiag);
            
            solve(board, row+1, ans);

            // remove Q
            board[row][col] = '.';
            // places (avialable) where we can put Q in future after not putting a Q in above position
            cols.erase(col);
            diag.erase(constDiag);
            antiDiag.erase(constAntiDiag);
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.')); // n=3 -> {"...", "...", "..."}
        vector<vector<string>> ans;
        solve(board, 0, ans);
        return ans;
    }
};