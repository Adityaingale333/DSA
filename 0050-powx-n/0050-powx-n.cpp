class Solution {
public:
    double myPow(double x, int n) {
        int m = n;
        n = abs(n);
        double ans = 1;

        while(n > 0){
            if(n%2 == 1){
                ans = ans*x;
                n = n-1;
            }
            else{
                n = n/2;
                x = x*x;
            }
        }
        if(m<0) return 1/ans;

        return ans;
    }
};