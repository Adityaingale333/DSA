class Solution {
public:
    bool isPallindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++, j--;
        }
        return 1;
    }
    int solve(int i, int j, string& s, vector<vector<int>>& t){
        if(i >= j){
            return 0;
        }
        if(isPallindrome(s, i, j)){
            return 0;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int cuts = INT_MAX;
        for(int k=i; k<=j-1; k++){ // k, j-1 tak hi jayega kuki k+1 kr rahe hai
            if(isPallindrome(s, i, k)){
                int left = 0;
                if(t[i][k] != -1){
                    left = t[i][k];
                } 
                else{
                    left = solve(i, k, s, t);
                }
                int right = 0;
                if(t[k+1][j] != -1){
                    right = t[k+1][j];
                }
                else{
                    right = solve(k+1, j, s, t);
                } 
                int temp = 1 + left + right; // 1 current partition ka add kra hai
                cuts = min(cuts, temp);
            }
            
        }
        return t[i][j] = cuts;
    }
    int minCut(string s) {
        int n = s.size();

        vector<vector<int>> t(n, vector<int>(n, -1));
        return solve(0, n-1, s, t);
    }
};