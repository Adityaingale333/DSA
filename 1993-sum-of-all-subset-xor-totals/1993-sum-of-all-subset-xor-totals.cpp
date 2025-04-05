class Solution {
public:
    // observation
    // take OR of all elements, and then append (n-1) times zero at the end
    // [1,3]  1 -> 01      3 -> 11
    // 1 OR 3 -> 11
    // ans = 6   6 -> 110,   append (2-1) times zero
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            ans = ans | nums[i];
        }

        return ans << (n-1);
    }
};