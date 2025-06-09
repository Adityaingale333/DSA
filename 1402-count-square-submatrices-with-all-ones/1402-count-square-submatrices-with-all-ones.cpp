class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        int ans = 0;
        for(int i=0; i<m; i++){
            t[i][0] = matrix[i][0];
            ans = ans + t[i][0];
        }
        for(int j=1; j<n; j++){ // start from 1 to avoid double counting of t[0][0]
            t[0][j] = matrix[0][j];
            ans = ans + t[0][j];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    t[i][j] = 0;
                }
                else{
                    // +1 to khudke liye, aur upar niche or side me jo bhi minimun hoga wo
                    // kyuki agar 3no me se koi ek bhi 1 nahi hua to square nahi ban skta 
                    t[i][j] = min({t[i-1][j], t[i][j-1], t[i-1][j-1]}) + 1; 
                } 
                ans = ans + t[i][j];
            }
        }

        return ans;
    }
};