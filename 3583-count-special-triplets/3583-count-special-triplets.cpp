class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
    int n = nums.size();
    long long result = 0;

    unordered_map<int, int> leftFreq;
    unordered_map<int, int> rightFreq;

    // Count frequency of each number in rightFreq
    for (int x : nums) {
        rightFreq[x]++;
    }

    // Iterate j from 0 to n - 1
    for (int j = 0; j < n; ++j) {
        rightFreq[nums[j]]--;  // We're at j now

        int target = nums[j] * 2;

        int countLeft = leftFreq[target];
        int countRight = rightFreq[target];

        result = (result + 1LL * countLeft * countRight) % MOD;

        leftFreq[nums[j]]++;  // Move j into the left part
    }

    return result;
    }
};