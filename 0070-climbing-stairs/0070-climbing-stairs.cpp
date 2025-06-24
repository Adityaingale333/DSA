class Solution {
public:
    int solve(int i, int n, vector<int>& t){
        if(i > n){
            return 0;
        }
        if(i == n){
            return 1;
        }
        if(t[i] != -1){
            return t[i];
        }

        int one = solve(i+1, n, t);

        int two = solve(i+2, n, t);

        return t[i] = one + two;
    }
    int climbStairs(int n) {
        vector<int> t(n+1, -1);
        return solve(0, n, t);
    }
};