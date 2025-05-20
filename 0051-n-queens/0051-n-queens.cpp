class Solution {
public:
    int N;
    bool isValid(vector<string>& board, int row, int col){
        // attack from vertically upward
        for(int i=row-1; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // attack from diagonally upward right
        for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++){
                if(board[i][j] == 'Q'){
                    return false;
                }
        }

        // attack from diagonally upward left
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
                if(board[i][j] == 'Q'){
                    return false;
                }
        }
        return true;
    }
    void solve(vector<string>& board, int row, vector<vector<string>>& ans){
        if(row == N){
            ans.push_back(board);
            return;
        }

        for(int col=0; col<N; col++){
            if(isValid(board, row, col)){
                board[row][col] = 'Q';
                solve(board, row+1, ans);
                board[row][col] = '.';
            }
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