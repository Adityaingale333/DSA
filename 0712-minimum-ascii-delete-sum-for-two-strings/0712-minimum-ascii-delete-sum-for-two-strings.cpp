class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(s1[i] == s2[j]){
                    t[i+1][j+1] = t[i][j] + s1[i];
                }
                else{
                    t[i+1][j+1] = max(t[i][j+1], t[i+1][j]);
                }
            }
        }

        int sum = 0;
        for(char c : s1){
            sum += c;
        }

        for(char c : s2){
            sum += c;
        }

        return sum - (2 * t[m][n]);
    }
};