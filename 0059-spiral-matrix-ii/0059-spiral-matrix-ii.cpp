class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int val = 1;
        int id = 0;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;

        while(top<=down && left<=right){
            // left to right
            if(id == 0){
                for(int i=left; i<=right; i++){
                    matrix[top][i] = val;
                    val++;
                }
                top++;
            }
            // top to down
            if(id == 1){
                for(int i=top; i<=down; i++){
                    matrix[i][right] = val;
                    val++;
                }
                right--;
            }
            // right to left
            if(id == 2){
                for(int i=right; i>=left; i--){
                    matrix[down][i] = val;
                    val++;
                }
                down--;
            }
            // down to top
            if(id == 3){
                for(int i=down; i>=top; i--){
                    matrix[i][left] = val;
                    val++;
                }
                left++;
            }
            id = (id+1)%4;
        }
        return matrix;
    }
};