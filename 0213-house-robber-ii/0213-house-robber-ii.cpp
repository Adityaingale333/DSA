class Solution {
public:
    int solve(int start, int end, vector<int>& nums,  vector<int>& t){
        if(end < start){
            return 0;
        }

        if(t[end] != -1){
            return t[end];
        }

        int take = nums[end] + solve(start, end-2, nums, t);
        int skip = 0 + solve(start, end-1, nums, t);

        return t[end] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> t1(n+1, -1);
        vector<int> t2(n+1, -1);

        int takeZero = solve(0, n-2, nums, t1); // we rob house no.(0) means we can not rob last(n-1) house, rob (n-2) house
        int skipZero = solve(1, n-1, nums, t2); // we skip house no.(0) means we can rob the last house 

        return max(takeZero, skipZero);
    }
};