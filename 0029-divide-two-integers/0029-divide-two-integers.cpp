class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(divisor<0 && dividend>=0) sign = false;
        else if(divisor>0 && dividend<=0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);
        long quotient = 0;

        while(n >= d){
            int count = 0;
            while(n >= d << (count+1)){
                count = count+1;
            }
            quotient = quotient + (1 << count);
            n = n - (d << count);
        } 
        if(quotient == (1 << 31) && sign){
            return INT_MAX;
        }
        else if(quotient == (1 << 31) && !sign){
            return INT_MIN;
        }
        return sign ? quotient : -quotient ;
    }
};