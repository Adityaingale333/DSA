class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

        int minC1 = max(0, n-(2*limit) );
        int maxC1 = min(n, limit); // agar choc hi 2 hai, to 100 limit ka kya karu

        for(int i = minC1; i <= maxC1; i++){
            int N = n-i;

            int minC2 = max(0, N-limit);
            int maxC2 = min(N, limit);

            ways = ways + (maxC2-minC2+1);
        }
        return ways;
    }
};