class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // check first row impacted hai ya nahi
        for(int col=0; col<n; col++){
            if(matrix[0][col] == 0){
                firstRowImpacted = true;
                break;
            }
        }

        // check first col impacted hai ya nahi
        for(int row=0; row<m; row++){
            if(matrix[row][0] == 0){
                firstColImpacted = true;
                break;
            }
        }
        
        // set markers in the first row/col in matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // using markers set row and col elements as zero
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // check for affected row/col and make it zero if required
        if(firstRowImpacted){
            for(int col=0; col<n; col++){
                matrix[0][col] = 0;
            }
        }

        // check for affected row/col and make it zero if required
        if(firstColImpacted){
            for(int row=0; row<m; row++){
                matrix[row][0] = 0;
            }
        }
        
    }
};