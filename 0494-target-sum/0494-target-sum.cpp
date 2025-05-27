class Solution {
public:
    // BASE CASE to handle 0's in the array
        // if(s1 == 0 && nums[0] == 0) return 2;
    // When both the target sum s1 is 0 and arr[0] is also 0:
    // You have two valid subsets: One that includes the zero , One that excludes the zero
    //  Both lead to sum = 0, so count = 2.
        //  if(s1 == 0 && s1 == nums[0]) return 1;
    // If either:
    // s1 == 0: You can form a subset (the empty subset) without using any element → 1 valid way
    // s1 == arr[0]: You can pick only this one element to form the subset → 1 valid way
    // So return 1.
        // return 0;
    // If none of the above conditions are satisfied:
    // You cannot form s1 using only arr[0].
    // So return 0.
    int solve(int i, int s1, vector<int>& nums, vector<vector<int>>& t){
        if(i == 0){
            if(s1 == 0 && nums[0] == 0) return 2;
            if(s1 == 0 || s1 == nums[0]) return 1;
            return 0;
        }

        if(t[i][s1] != -1){
            return t[i][s1];
        }

        int notTake = solve(i-1, s1, nums, t);

        int take = 0;
        if(nums[i] <= s1){
            take = solve(i-1, s1-nums[i], nums, t);
        }
        return t[i][s1] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        // s1 - s2 = target -> s1 + s2 = sum
        // s1 - (sum - s1) = target -> s1 = (target + sum)/2
        int s1 = (target + sum)/2;

        if(sum < abs(target) || (target+sum)%2 != 0) return 0;

        vector<vector<int>> t(n, vector<int>(s1+1, -1));

        return solve(n-1, s1, nums, t);
    }
};