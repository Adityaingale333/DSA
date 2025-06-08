class Solution {
public:
    bool isPallindrome(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    /*int solve(int i, int n, string& s, vector<int>& t){
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
    }*/
    int minCut(string s) {
        int n = s.size();
        vector<int> t(n+1, 0);

        t[n] = 0;

        for(int i=n-1; i>=0; i--){
            int minCost = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPallindrome(i, j, s)){
                    int cost = 1 + t[j+1];
                    minCost = min(minCost, cost); 
                }
            }
            t[i] = minCost;
        }
        return t[0] - 1; // it is doing partition for the last character as well
                                    // so we need to minus 1,  a|b|c| <- delete this last partiton
    }
};