class Solution {
public:
    int lcs(string word1, string word2){
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m+1; i++){
            t[i][0] = 0;
        }
        for(int j=0; j<n+1; j++){
            t[0][j] = 0;
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1] == word2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int lenLCS = lcs(word1, word2);

        return (m-lenLCS) + (n-lenLCS);
    }
};