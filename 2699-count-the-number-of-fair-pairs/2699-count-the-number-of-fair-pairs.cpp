class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long result = 0;

        for(int i=0; i<n; i++){
            // gives the first element not less than (lower - nums[i])
            int idx = lower_bound( nums.begin() + i + 1, nums.end(), lower-nums[i] ) - nums.begin();

            int x = idx - i - 1;
            
            // gives the first element greater than (upper - nums[i])
            idx = upper_bound( nums.begin() + i + 1, nums.end(), upper-nums[i] ) - nums.begin();

            int y = idx - i - 1;

            result = result + (y-x);
        }
        return result;
    }
};