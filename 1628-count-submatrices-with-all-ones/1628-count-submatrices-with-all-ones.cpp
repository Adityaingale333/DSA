class Solution {
public:
    int oneD_Array_Count(vector<int>& vec){
        int cons = 0;
        int subCount = 0;

        for(auto& val : vec){
            if(val == 0){
                cons = 0;
            }
            else{
                cons++;
            }

            subCount = subCount + cons;
        }

        return subCount;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        for(int startRow = 0; startRow < m; startRow++){
            vector<int> vec(n, 1);
            for(int endRow = startRow; endRow < m; endRow++){
                
                for(int col=0; col<n; col++){
                    vec[col] = vec[col] & mat[endRow][col];
                }

                ans = ans + oneD_Array_Count(vec);
            } 
        }

        return ans;
    }
};