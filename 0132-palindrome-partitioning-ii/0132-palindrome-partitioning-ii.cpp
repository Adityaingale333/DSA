class Solution {
public:
    bool isPallindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int solve(int i, int n, string& s, vector<int>& t){
        if( i == n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        int minCost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPallindrome(i, j, s)){
                int cost = 1 + solve(j+1, n, s, t);
                minCost = min(minCost, cost); 
            }
        }
        return t[i] = minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> t(n, -1);
        return solve(0, n, s, t) - 1; // it is doing partition for the last character as well
                                    // so we need to minus 1,  a|b|c| <- delete this last partiton
    }
};