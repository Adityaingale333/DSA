class Solution {
public:
   /* // using lcs we can only compute insert and delete operations
    // to compute all 3 insert delete and replace, we need to write recurssion of match - notMatch
    int solve(int i, string&word1, int j, string& word2, vector<vector<int>>& t){
        if(j < 0){
            return i+1; // word2 in finished, so we will need to delete word1 of i+1 length
        }
        if(i < 0){
            return j+1; // word1 is finished, so we will need to insert the remaining word2 of j+1 length
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(word1[i] == word2[j]){
            return t[i][j] = solve(i-1, word1, j-1, word2, t);
        }

        // if above condition is false, then only this below will run
        int insert = 1 + solve(i, word1, j-1, word2, t); // only i will move
        int remove = 1 + solve(i-1, word1, j, word2, t); // only j will move
        int replace = 1 + solve(i-1, word1, j-1, word2, t); // both will move

        return t[i][j] = min(insert, min(remove, replace));
    }*/
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i=0; i<m+1; i++){
            t[i][0] = i; // i+1 but here indexing changes so, i -> i-1, so i+1 = (i-1) + 1
        }
        for(int j=0; j<n+1; j++){
            t[0][j] = j;
        }

        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }
                else{
                   int insert = 1 + t[i][j-1];
                   int remove = 1 + t[i-1][j];
                   int replace = 1 + t[i-1][j-1];
                   t[i][j] = min(insert, min(remove, replace)); 
                }
            }
        }
        return t[m][n] ;
    }
};