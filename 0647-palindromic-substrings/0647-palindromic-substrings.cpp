class Solution {
public:
    bool isPallindrome(string& s, int i, int j, vector<vector<int>>& t){
        if(i > j){
            return true;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == s[j]){
           return t[i][j] = isPallindrome(s, i+1, j-1, t);
        }

        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        vector<vector<int>> t(n, vector<int>(n, -1));

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPallindrome(s, i, j, t)){
                    count++;
                }
            }
        }
        return count;
    }
};