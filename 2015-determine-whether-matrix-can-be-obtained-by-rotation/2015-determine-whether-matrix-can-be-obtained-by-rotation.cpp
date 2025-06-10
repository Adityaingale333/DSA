class Solution {
public:
    void rotate(int n, vector<vector<int>>& mat){
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        return;
    }
    /*bool compare(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }*/
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        bool ans = (mat == target);

        rotate(n, mat);
        ans = ans || (mat == target) ;
    
        rotate(n, mat);
        ans = ans || (mat == target) ;

        rotate(n, mat);
        ans = ans || (mat == target) ;

        return ans; 
    }
};