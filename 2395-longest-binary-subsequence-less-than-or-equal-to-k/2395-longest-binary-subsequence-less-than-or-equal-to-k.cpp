class Solution {
public:
    // recursion approach is giving tle, so we will have to go for more optimized approach
    // if we observe that if we start iterating from back of the string and keeps adding bits such that it is <= k
    // we will be able to solve it in O(n), in single pass
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        int powerVal = 1; // 2^0

        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                maxLen++;
            }
            else if(1 * powerVal <= k){
                k = k - powerVal;
                maxLen++;
            }

            if(powerVal <= k){
                powerVal = powerVal * 2; 
            }
        }
        return maxLen;
    }
};