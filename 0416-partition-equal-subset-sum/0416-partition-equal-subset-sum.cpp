class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int i, int x){
        // Base case: if we've formed the required sum, return true
        if(x == 0){
            return true;
        }

        // If we've exhausted the array, and haven't formed the sum, return false
        if(i >= nums.size()){
            return false;
        }

        if(t[i][x] != -1){
            return t[i][x];
        }

        // Option 1: take nums[i] if it doesn't exceed the remaining sum
        bool take = false;
        if(nums[i] <= x){
            take = solve(nums, i+1, x-nums[i]);
        }

        // Option 2: skip nums[i]
        bool not_take = solve(nums, i+1, x);

        // Store and return the result of either taking or skipping the current element
        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // total sum
        int S = accumulate(nums.begin(), nums.end(), 0);

        // If total is odd, it cannot be split into two equal subsets
        if(S % 2 != 0){
            return false;
        }

        memset(t, -1, sizeof(t));

        // We need to find a subset with sum equal to total/2
        int x = S/2;

        return solve(nums, 0, x);

    }
};