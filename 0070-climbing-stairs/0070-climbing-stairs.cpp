class Solution {
public:
    int t[46];
    int solve(int sum, int n){
        if(sum > n){
            return 0;
        }

        if(sum == n){
            return 1;
        }

        if(t[sum] != -1){
            return t[sum];
        }

       return t[sum] = solve(sum+1, n) + solve(sum + 2, n);
        
        
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        int ans = 0;
        int sum = 0;
        return solve(sum, n);
    }
};