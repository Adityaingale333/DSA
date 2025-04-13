class Solution {
public:
// Modular Exponentiation (findPower):
// Compute a^b mod M efficiently in O(log b) time.
// Uses divide and conquer:
//     -> if b is even : result = (a^b/2)^2;
//     -> if b is odd : result = a(a^b/2)^2;
// Total Good Numbers:
//     -> number of even index : (n+1)/2, possible number : (0 2 4 6 8) -> 5
//         -> total possible numbers for even index = 5^((n+1)/2)
//     -> number of odd index : n/2, possible number : (2 3 5 7) -> 4
//         -> total possible numbers for odd index = 4^(n/2)
//     -> ans = 5^((n+1)/2) * 4^(n/2)
    const int M = 1e9 + 7;
    int findPower(long long a, long long b){
        if(b == 0){
            return 1;
        }

        long long half = findPower(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1){
            result = (result * a) % M;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
    }
};