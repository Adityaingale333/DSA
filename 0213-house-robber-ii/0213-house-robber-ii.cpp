class Solution {
public:
    int solve(int start, int end, vector<int>& nums){
        int len = end - start + 1; // total houses we are considering, n houses
        int prev2 = 0; //this is t[0], after robbing 0 house
        int prev = nums[start]; //this is t[1], after robbing only startting house

        for(int i=2; i<=len; i++){ // end+1 -> if n elements then total n+1 index, n-2 elements -> end+1 -> n-1 index
            int pick = nums[start + i - 1] + prev2; // start is added to take account of correct house
            int skip = prev;
            int curri = max(pick, skip);

            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int takeZero = solve(0, n-2, nums); // we rob house no.(0) means we can not rob last(n-1) house, rob (n-2) house
        int skipZero = solve(1, n-1, nums); // we skip house no.(0) means we can rob the last house 

        return max(takeZero, skipZero);
    }
};