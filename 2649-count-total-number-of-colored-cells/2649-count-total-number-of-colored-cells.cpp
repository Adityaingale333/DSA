class Solution {
public:
// using mathematical relation and pattern recognizing
// n = 1 -> 1
// n = 2 -> 1 + 4(2-1)
// n = 3 -> 1 + 4(2-1) + 4(3-1)
// n = 4 -> 1 + 4(2-1) + 4(3-1) + 4(4-1)
// ....... taking 4 common -> 1 + 4[sum of n-1 natural numbers]
// -> 1 + 4* { (n-1)(n-1+1)/2 }   ->  1 + 2*{(n-1)(n)}   
    long long coloredCells(int n) {
        return 1 + 2*( (long long)(n-1)*(n) );
    }
};