class Solution {
public:
    int M = 1e9+7;

    int solve(int day, int delay, int forget, vector<int>& t){
        if(day == 1){
            return 1;
        }

        if(t[day] != -1){
            return t[day];
        }

        int result = 0;
        for(int prev = day-forget+1; prev <= day-delay; prev++){
            if(prev > 0){
                result = ( result + solve(prev, delay, forget, t) )% M;
            }
        }
        return t[day] = result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        
        vector<int> t(n+1, -1);
        
        for(int day = n-forget+1; day <= n; day++){
            if(day > 0){
                total = ( total + solve(day, delay, forget, t) ) % M;
            }
        }

        return total;
    }
};