class Solution {
public:
 // Using BIT MANIPULATION
 // take xor from 0 to n
 // take xor of array
 // take resultant xor, it will cancel out all the element occuring double, leaving missing
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;
        for(int i=0; i<=n; i++){
            xor1 = xor1 ^ i; 
        }
        for(int i=0; i<n; i++){
            xor2 = xor2 ^ nums[i];
        }
        int ans = xor1 ^ xor2;
        return ans;
    }
};