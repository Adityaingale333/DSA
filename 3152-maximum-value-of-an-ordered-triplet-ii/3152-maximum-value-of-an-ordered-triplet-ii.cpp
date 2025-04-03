class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();

    long long result = 0;
    long long max_i = nums[0];  // Stores maximum `nums[i]` encountered so far
    long long maxDiff = LLONG_MIN; // Stores maximum (nums[i] - nums[j]) encountered

    for (int k = 1; k < n; k++) {
        if (k >= 2) {
            result = max(result, maxDiff * nums[k]);  // Compute maximum triplet value
        }
        maxDiff = max(maxDiff, max_i - nums[k]);  // Update max(i - j)
        max_i = max(max_i, (long long)nums[k]);  // Update max(nums[i])
    }

    return max(result, 0LL);  // Ensure non-negative result
    }
};