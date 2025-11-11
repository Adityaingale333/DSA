class Solution {
public:
    int solve(int i, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& t){
        if(i >= strs.size()){
            return 0;
        }

        if(t[i][m][n] != -1){
            return t[i][m][n];
        }

        int count0 = 0;
        int count1 = 0;
        for(int j=0; j<strs[i].size(); j++){
            if(strs[i][j] == '1'){
                count1++;
            }
            else{
                count0++;
            }
        }

        int take = 0;
        if(count0 <= m && count1 <= n){
            take = 1 + solve(i+1, strs, m-count0, n-count1, t);
        }

        int notTake = solve(i+1, strs, m, n, t);

        return t[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> t(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return solve(0, strs, m, n, t);
    }
};