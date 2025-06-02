class Solution {
public:
    int solve(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& t){
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
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        return solve(0, 0, m, triangle, t);
    }
};