class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, int idx, string word){
        if(idx == word.length()){
            return true;
        }

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == '$'){
            return false;
        }

        if(board[i][j] != word[idx]) return false;

        char ch = board[i][j]; 
        board[i][j] = '$';

        if(solve(i-1, j, board, idx+1, word)){
            return true;
        }

        if(solve(i, j+1, board, idx+1, word)){
            return true;
        }

        if(solve(i, j-1, board, idx+1, word)){
            return true;
        }

        if(solve(i+1, j, board, idx+1, word)){
            return true;
        }
        
        board[i][j] = ch;

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        string temp = "";
        bool isPossible = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    isPossible = solve(i, j, board, 0, word);
                    if(isPossible){
                        return true;
                    }
                }
            }
        }
        return isPossible;
    }
};