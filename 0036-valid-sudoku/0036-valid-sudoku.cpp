class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++){
            unordered_set<char> st;
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    if(st.count(board[i][j])){
                        return false;
                    }
                    st.insert(board[i][j]);
                }
            }
        }

        for(int j=0; j<9; j++){
            unordered_set<char> st;
            for(int i=0; i<9; i++){
                if(board[i][j] != '.'){
                    if(st.count(board[i][j] - '0')){
                        return false;
                    }
                    st.insert(board[i][j] - '0');
                }
            }
        }

        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                unordered_set<char> st;
                for(int k=0; k<3; k++){
                    for(int l=0; l<3; l++){
                        char c = board[i+k][j+l];

                        if(c != '.'){
                            if(st.count(c)){
                                return false;
                            }
                            st.insert(c);
                        }
                    }
                }
            }
        }

        return true;
    }
};