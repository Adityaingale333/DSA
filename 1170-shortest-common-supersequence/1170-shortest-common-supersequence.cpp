class Solution {
public:
    // to generate shortest common subsequence we use dp table of lcs
    // we will start from last cell of dp table
    // and look for the element which are common in both, so we use them only once
    // other elements which are not common we will have to include all of them 
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m+1; i++){
            t[i][0] = 0;
        }
        for(int j=0; j<n+1; j++){
            t[0][j] = 0;
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int i=m, j=n;
        string ans = "";

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans = ans + str1[i-1];
                i--, j--;
            }
            else if(t[i-1][j] > t[i][j-1]){
                ans = ans + str1[i-1];
                i--;
            }
            else{
                ans = ans + str2[j-1];
                j--;
            }
        }

        while(i > 0){
            ans = ans + str1[i-1];
            i--;
        }
        while(j > 0){
            ans = ans + str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};