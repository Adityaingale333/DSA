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
            //go right
            if(id==0){
                for(int i=left; i<=right; i++){
                    matrix[top][i] = val;
                    val++;
                }
                top++;
            }
            //go down
            if(id==1){
                for(int i=top; i<=down; i++){
                    matrix[i][right] = val;
                    val++;
                }
                right--;
            }
            //go left
            if(id==2){
                for(int i=right; i>=left; i--){
                    matrix[down][i] = val;
                    val++;
                }
                down--;
            }
            //go top
            if(id==3){
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