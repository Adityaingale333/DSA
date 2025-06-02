class Solution {
public:
    /*int solve(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& t){
        if(i==m-1){
            return triangle[i][j];
        }
        if(i>m){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int sameIdx = triangle[i][j] + solve(i+1, j, m, triangle, t);

        int nextIdx = triangle[i][j] + solve(i+1, j+1, m, triangle, t);

        return t[i][j] = min(sameIdx, nextIdx);
    }*/
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            t[m-1][j] = triangle[m-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int sameIdx = triangle[i][j] + t[i+1][j];
                int nextIdx = triangle[i][j] + t[i+1][j+1];
                t[i][j] = min(sameIdx, nextIdx);
            }
        }
        return t[0][0] ;
    }
};