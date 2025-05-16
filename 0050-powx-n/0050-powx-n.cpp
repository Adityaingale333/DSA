class Solution {
public:
    double solve(double x, long long m){
        if(m == 0){
            return 1.0;
        }

        double half = solve(x, m/2);

        if(m%2 == 0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long long m = n;
        double ans = solve(x, abs(m));
        if(n < 0) return 1/ans;
        return ans;
    }
};